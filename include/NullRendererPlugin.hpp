#ifndef NULLRENDERERPLUGIN_H_
#define NULLRENDERERPLUGIN_H_

#include <memory>

#include "IGraphicsPlugin.hpp"

namespace ice_engine
{

class NullRendererPlugin : public IGraphicsPlugin
{
public:
	NullRendererPlugin();
	virtual ~NullRendererPlugin();

	virtual std::string getName() const override;

	virtual std::unique_ptr<graphics::IGraphicsEngineFactory> createFactory() const override;

};

}

#endif /* NULLRENDERERPLUGIN_H_ */
