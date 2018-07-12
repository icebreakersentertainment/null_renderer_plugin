#include "NullRendererFactory.hpp"

#include "NullRenderer.hpp"

namespace ice_engine
{
namespace graphics
{
namespace null_renderer
{

NullRendererFactory::NullRendererFactory()
{
}

NullRendererFactory::~NullRendererFactory()
{
}

std::unique_ptr<IGraphicsEngine> NullRendererFactory::create(
	utilities::Properties* properties,
	fs::IFileSystem* fileSystem,
	logger::ILogger* logger
)
{
	std::unique_ptr<IGraphicsEngine> ptr = std::make_unique< NullRenderer >( properties, fileSystem, logger );
	
	return std::move( ptr );
}

}
}
}
