#ifndef NULLRENDERERFACTORY_H_
#define NULLRENDERERFACTORY_H_

#include <memory>

#include "graphics/IGraphicsEngine.hpp"
#include "graphics/IGraphicsEngineFactory.hpp"

namespace ice_engine
{
namespace graphics
{
namespace null_renderer
{

class NullRendererFactory : public IGraphicsEngineFactory
{
public:
	NullRendererFactory();
	virtual ~NullRendererFactory();

	virtual std::unique_ptr<IGraphicsEngine> create(
		utilities::Properties* properties,
		fs::IFileSystem* fileSystem,
		logger::ILogger* logger
	) override;

};

}
}
}

#endif /* NULLRENDERERFACTORY_H_ */
