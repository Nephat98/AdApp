#ifndef ANIMATABLE_H
#define ANIMATABLE_H

namespace bgl {

/*
 * @brief
 */
class Animatable
{
	public:
		/*
		 * @brief
		 */
		virtual void start(void) = 0;
		
		/*
		 * @brief
		 */
		virtual void stop(void) = 0;
		
		/*
		 * @brief
		 */
		virtual void pause(void) = 0;
		
		/*
		 * @brief
		 */
		virtual void unpause(void) = 0;
};

}
#endif