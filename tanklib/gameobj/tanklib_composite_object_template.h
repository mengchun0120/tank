#ifndef INCLUDED_TANKLIB_COMPOSITE_OBJECT_TEMPLATE_H
#define INCLUDED_TANKLIB_COMPOSITE_OBJECT_TEMPLATE_H

#include <vector>
#include <tanklib_component.h>
#include <tanklib_typedef.h>
#include <tanklib_game_object_template.h>

namespace mcdane {
namespace tanklib {

class CompositeObjectTemplate: public GameObjectTemplate {
public:
    CompositeObjectTemplate() = default;

    ~CompositeObjectTemplate() override;

    void init(GameObjectType t,
              const std::string &name,
              const rapidjson::Value &v,
              const ComponentTemplateLib &componentTemplateLib);

    inline int numComponents() const;

    inline const Component &component(unsigned int i) const;

private:
    void initComponents(
                const rapidjson::Value &v,
                const ComponentTemplateLib &componentTemplateLib);

    void resetSpan();

private:
    std::vector<Component *> components_;
};

int CompositeObjectTemplate::numComponents() const
{
    return static_cast<int>(components_.size());
}

const Component &CompositeObjectTemplate::component(unsigned int i) const
{
    return *(components_[i]);
}

} // end of namespace tanklib
} // end of namespace mcdane

#endif

