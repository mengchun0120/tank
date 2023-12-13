#ifndef INCLUDED_TANKLIB_TYPEDEF_H
#define INCLUDED_TANKLIB_TYPEDEF_H

#include <memory>
#include <functional>

namespace mcdane {
namespace commonlib {

template <typename T>
class NamedMap;

template <typename T>
class LinkedItem;

template <typename T>
class LinkedList;

template <typename T>
class ObjectPool;

class Texture;
class VertexArray;

} // end of namespace commonlib
} // end of namespace mcdane

namespace mcdane {
namespace tanklib {

class GameObject;
class Rectangle;
class ComponentTemplate;
class TileTemplate;
class MissileTemplate;
class GoodieTemplate;
class AIRobotTemplate;
class ParticleEffectTemplate;
class ProgressPieTemplate;
class ProgressBarTemplate;
class IconTemplate;
class SkillTemplate;

using TextureLib = commonlib::NamedMap<commonlib::Texture>;
using VertexArrayLib = commonlib::NamedMap<commonlib::VertexArray>;
using RectLib = commonlib::NamedMap<Rectangle>;
using ComponentTemplateLib = commonlib::NamedMap<ComponentTemplate>;
using TileTemplateLib = commonlib::NamedMap<TileTemplate>;
using GoodieTemplateLib = commonlib::NamedMap<GoodieTemplate>;
using MissileTemplateLib = commonlib::NamedMap<MissileTemplate>;
using AIRobotTemplateLib = commonlib::NamedMap<AIRobotTemplate>;
using ParticleEffectTemplateLib = commonlib::NamedMap<ParticleEffectTemplate>;
using ProgressPieTemplateLib = commonlib::NamedMap<ProgressPieTemplate>;
using ProgressBarTemplateLib = commonlib::NamedMap<ProgressBarTemplate>;
using IconTemplateLib = commonlib::NamedMap<IconTemplate>;
using SkillTemplateLib = commonlib::NamedMap<std::unique_ptr<SkillTemplate>>;
using GameObjectList = commonlib::LinkedList<GameObject>;
using GameObjectItem = commonlib::LinkedItem<GameObject*>;
using GameObjItemPool = commonlib::ObjectPool<GameObjectItem>;
using GameObjItemList = commonlib::LinkedList<GameObjectItem>;
using GameObjItemDeleter = std::function<void(GameObjectItem*)>;
using GameObjDeleter = std::function<void(GameObject*)>;

} // end of namespace tanklib
} // end of namespace mcdane

#endif

