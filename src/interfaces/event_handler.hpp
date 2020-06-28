#ifndef _EVENT_HANDLER_HPP_
#define _EVENT_HANDLER_HPP_

class IEventHandler
{
public:
  virtual void on_event(/*event type*/) = 0;
};

#endif
