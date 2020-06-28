
#include "../interfaces/event_handler.hpp"
#include "../physics/physics_types.hpp"

enum class ActorType
{
  player,
  alien,
  missile
};

class Actor : public IEventHandler
{
public:
  Actor();

  virtual ~Actor();

  virtual void on_event(/*event type*/);
  virtual void on_tick();

private:
  enum ActorType type;
  unsigned int uid;

  Position2D origin_w;
};
