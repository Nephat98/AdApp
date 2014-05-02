
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
		 * Führt Befehle aus
		 */
		void walkTo(Coordinate x)
		{
			// Checks if a current route to be cancelled exists
			{
				// Cancels current command
			}
			
			// Issues commands
			
			if(position.x == x)
			{
				// does nothing
			}
			else // Walk Left oder right
			{
				// Computes Walking Time 
				
				// Starts animations
				if(position.x > x)
				else 
			}
	
		}

	public:
		/*
		 * Checkt policies
		 */
		void goTo(const Position& position)
		{
		
			// Check 
		
		
		
			if(position.x == position.
		
			// Testen,ob überhaupt möglich)
		
			// Nur Springen
			// Nur walk:
			
			// Beides jump and walk(wiederholt):
			//
		}
		
	
	
	
	
	
	
	
	
	
		Position position;
		
		/*
		 *
		 */
		class Movement
		{
			public:
				void setAnimation
				void setCallback
				
			private:
				notify
				notify
		};
		
		/*
		 *
		 */
		class MovementPolicy
		{
		
		};

				
		// TODO: Default Policy;
		

		
		void setMovementPolicy(
		void setMove

		
		
	public:
	

		
		
		
	
		
	private:
		std::queue<std::function<void(void)>> moveQueue;
		
	
			
			
			// Stand am Ende in die Animation Queue
		}

		// Animations bedingt
		
		void notifyWalkBegin(void)
		void notifyWalkEnd(void)
		
		void notifyStandBegin(void) // Begin und end sind gleich am Anfang
		void notifyStandEnd(void)
		
}

#ifdef

void CreateCharacter
{

	Character character;
	
	// TODO: Registers all moves

	
	// Sets the move policy
	MovePolicy movePolicy;
	
	movePolicy->setMove

	character->setMovePolicy(movePolicy);
	
	
	return charcater;
}

#end





/*
 *
 */
class WalkCommand : public MoveCommand
{
	public
		virtual void perform(void)
		{}
		
	private:
		{
		
			// start Animation
		}
		
}

// dgsssf






// Auswahl: Policy gefragt
Laufen in eine ungültige Position
	(1) Zulassen?
	(2) nahe gültige Position suchen
	
	(3) Ausrechnen wie lange Animation gehen wird
	(3) Animation starten (in Liste packen)
	(3) Animation starten
	
	
	
Laufen und dann richtung wechseln in eine ungültige Position



//Alles Perfekt
Laufen:
	
	LaufAnimation 
Laufen und dann Richtung wechseln

class AnimationQueue
{

}

quue.next();
























