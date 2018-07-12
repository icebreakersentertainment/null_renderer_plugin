#include <boost/config.hpp> // for BOOST_SYMBOL_EXPORT

#include "NullRendererPlugin.hpp"

#include "NullRendererFactory.hpp"

namespace ice_engine
{

NullRendererPlugin::NullRendererPlugin()
{
}

NullRendererPlugin::~NullRendererPlugin()
{
}

std::string NullRendererPlugin::getName() const
{
	return std::string("null_renderer");
}

std::unique_ptr<graphics::IGraphicsEngineFactory> NullRendererPlugin::createFactory() const
{
	std::unique_ptr<graphics::IGraphicsEngineFactory> ptr = std::make_unique< graphics::null_renderer::NullRendererFactory >();
	
	return std::move( ptr );
}

// Exporting `my_namespace::plugin` variable with alias name `plugin`
// (Has the same effect as `BOOST_DLL_ALIAS(my_namespace::plugin, plugin)`)
extern "C" BOOST_SYMBOL_EXPORT NullRendererPlugin plugin;
NullRendererPlugin plugin;

}
