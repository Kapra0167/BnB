#include "effect.h"

Effect::Effect(int id) : Component(),id(id) {}

void Effect::onAttach() {
  imagetransform = this->gameObject->getComponent<ImageTransform>();
  assert(imagetransform != nullptr );
}
void Effect :: onUpdate (float deltaTime)
{

}
