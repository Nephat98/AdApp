#include "Animation.h

class Animation
{
	private:
		std::forward_list<shared_ptr<Instance>> instances;
		
		registerInstance()
		unregisterInstance()
		
		
	public:
	
		setFrame()
		getFrameCount();
		getInstanceCount(void);
		
	public:
		class Instance : public Animatable
		{
		
			virtual void onStart(void)
			{}
		
			virtual void onPause(void)
			{}

			virtual void onUnpause(void)
			{}
			
			virtual void onStop(void)
			{}
				// Animatable Interface
				virtual void start(void)
				{}
				
				virtual void stop(void)
				{}
				
				virtual void pause(void)
				{}
				
				virtual void unpause(void)
				{}
		
		}
			
		getInstance()
		
		
	protected:

};



