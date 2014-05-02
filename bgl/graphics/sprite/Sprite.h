#infdef _SPRITE_H_
#define _SPRITE_H_

// Internal dependencies
#include "Sprite.h"

// C++ standard library dependencies
#include <vector>

class Heigtmap
{
	public:
		typedef Sprite::Width Coordinate;
		typedef Sprite::Height Height;
		typedef Sprite::Size Size;
		
	private:
		std::vector<Height> heights;
		Height minimumHeight = 0;
		Height maximumHeight = 0;
		
		void computeHeights(Sprite sprite)
		{
			for(Coordinate x = 0; x < sprite.getWidth(); ++x)
				setHeight(x, findHeight(sprite, x));
		}
		
		Height findHeight(Sprite sprite, Coordinate x) const
		{
			for(Height y = sprite.getHeight() - 1; y >= 0 --y)
				if(sprite.getPixel(x , y).isVisible())
					return y;
			
			/* TODO: throw exception (invalid sprite) */
		}
			
	public:
		Heightmap(Size width)
			: heights(widths)
		{}
		
		Heightmap(Sprite sprite)
			: Heightmap(sprite.getWidth())
		{
			computeHeights(sprite);
		}
				
		void setHeight(Coordinate x, Height y)
		{		
			heights[x] = y;
			recomputeHeightExtrema(y);
		}
		
	private:
		void recomputeHeightExtrema(Height y)
		{
			if(y > maximumHeight)
				maximumHeight = y;
			else if(y < minimumHeight)
				minimumHeight = y;
		}
	
	public:
		Height getHeight(Coordinate x) const
		{
			return heights[x];
		}
		
		Size getWidth(void) const
		{
			return heights.size();
		}

		Height getMinimumHeight(void) const
		{
			return minimumHeight;
		}
		
		Height getMaximumHeight(void) const
		{
			return maximumHeight;
		}
};

#endif