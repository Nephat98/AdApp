
#include "Command.h"

class CommandQueue : public TimerInterface
{
	public:
		void getCurrentCommand(void);
		void cancelCommand(void);
		void issue(void);
		virtual void pause(void)
		virtual void unpause(void)
	
	private:
		notifyCancel
};