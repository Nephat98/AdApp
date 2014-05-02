//
#include <queue>
#include <memory>

//
#include "Level.h"


namespace bgl {

/*
 *
 */
class Character
{
	public:
		//
		typedef Level::Position Position;
		typedef Position::Coordinate Coordinate;
		
	private:
		/*
		 * @brief Level on which the character performs
		 */
		std::shared_ptr<Level> level;
	
	
	
		
		/*
		 * @brief Queue of commands to be performed one after the other
		 */
		std::queue<Command> commands;
		
	public:
		
		bool isWalking(void) const
		bool isStanding(void) const
		getCurrentCommand()
		issueCommand();
		
	
		/*
		 * Führt Befehle aus
		 * //Geht davon auswww das weg frei ist
		 */
		void walkTo(Coordinate x)
		{
			if(isWalking())
				getCurrentCommand().setDestination(x);
			else
				issueCommand(std::make_unique<WalkCommand>(*this, x));
		}
}