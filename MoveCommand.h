

class MoveCommand : public Command
{
	private:
		Policy policy;
		
	public:
		virtual void start(int )
		virtual void start(void)
		setAnimation
}

class WalkCommand : public MoveCommand
{
	private:
		determineDirection
		
		

}


	
		
		////////////////////////
		class WalkCommand
		{
			public:
			
			void sas()
			{
				// Case 1: Change walk direction
				if()
				{
					// TODO: Change walk direction
				}
				// Case 2: Change walk distance
				else
				{
					
				}

				// Case: Weg verkürzt sich
				// Case: Weg verlängert sich
				// Case: Richtungswechsel
				
				{
					issueCommand()
				}
			}
		}
		///////////////
		

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
























