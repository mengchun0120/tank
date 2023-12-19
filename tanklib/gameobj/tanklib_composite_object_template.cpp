#include <utility>
#include <sstream>
#include <commonlib_log.h>
#include <commonlib_exception.h>
#include <commonlib_json_utils.h>
#include <commonlib_json_param.h>
#include <tanklib_component_template.h>
#include <tanklib_composite_object_template.h>

using namespace mcdane::commonlib;

namespace mcdane {
namespace tanklib {

CompositeObjectTemplate::~CompositeObjectTemplate()
{
    int count = numComponents();
    for (int i = 0; i < count; ++i)
    {
        delete components_[i];
    }
}

void CompositeObjectTemplate::init(
    GameObjectType t,
    const std::string &name,
    const rapidjson::Value &v,
    const ComponentTemplateLib &componentTemplateLib)
{
    initComponents(v, componentTemplateLib);
    GameObjectTemplate::init(t, name, v);
    resetSpan();
}

void CompositeObjectTemplate::initComponents(
    const rapidjson::Value &v,
    const ComponentTemplateLib &componentTemplateLib)
{
    const rapidjson::Value *a = findJson(v, {"components"});
    if (!a)
    {
        THROW_EXCEPT(ParseException, "Failed to find components");
    }

    if (!a->IsArray())
    {
        THROW_EXCEPT(ParseException, "components is not array");
    }

    if (a->Capacity() == 0)
    {
        THROW_EXCEPT(ParseException, "components is empty");
    }

    components_.resize(a->Capacity());
    for (unsigned int i = 0; i < a->Capacity(); ++i)
    {
        Component *c = new Component((*a)[i], componentTemplateLib);
        components_[i] = c;
    }
}

void CompositeObjectTemplate::resetSpan()
{
    for (std::size_t i = 0; i < components_.size(); ++i)
    {
        const Component &c = component(i);
        float s = c.pos().norm() + c.getTemplate()->span();
        if (s >= span_)
        {
            span_ = s;
        }
    }
}

} // end of namespace tanklib
} // end of namespace mcdane

