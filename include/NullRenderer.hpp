#ifndef NULLRENDERER_H_
#define NULLRENDERER_H_

#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/gtc/quaternion.hpp>

#include "graphics/IGraphicsEngine.hpp"

#include "utilities/Properties.hpp"
#include "logger/ILogger.hpp"
#include "fs/IFileSystem.hpp"

namespace ice_engine
{
namespace graphics
{
namespace null_renderer
{

class NullRenderer : public IGraphicsEngine
{
public:
	NullRenderer(utilities::Properties* properties, fs::IFileSystem* fileSystem, logger::ILogger* logger) {}
	virtual ~NullRenderer() {}

	virtual void setViewport(const uint32 width, const uint32 height) override {}
	virtual glm::uvec2 getViewport() const override { return {}; }
	
	virtual glm::mat4 getModelMatrix() const override { return {}; }
	virtual glm::mat4 getViewMatrix() const override { return {}; }
	virtual glm::mat4 getProjectionMatrix() const override { return {}; }
	
	virtual void beginRender() override {}
	virtual void render(const RenderSceneHandle& renderSceneHandle) override {}
	virtual void renderLine(const glm::vec3& from, const glm::vec3& to, const glm::vec3& color) override {}
	virtual void renderLines(const std::vector<std::tuple<glm::vec3, glm::vec3, glm::vec3>>& lineData) override {}
	virtual void endRender() override {}
	
	virtual RenderSceneHandle createRenderScene() override { return {0,1}; }
	virtual void destroyRenderScene(const RenderSceneHandle& renderSceneHandle) override {}
	
	virtual CameraHandle createCamera(const glm::vec3& position, const glm::vec3& lookAt = glm::vec3(0.0f, 0.0f, 0.0f)) override { return {0,1}; }
	
	virtual PointLightHandle createPointLight(const RenderSceneHandle& renderSceneHandle, const glm::vec3& position) override { return {0,1}; }
	virtual void destroy(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle) override {}
	
	virtual MeshHandle createStaticMesh(const IMesh* mesh) override { return {0,1}; }
	virtual MeshHandle createDynamicMesh(const IMesh* mesh) override { return {0,1}; }

	virtual SkeletonHandle createSkeleton(const MeshHandle& meshHandle, const ISkeleton* skelton) override { return {0,1}; }
	virtual void destroy(const SkeletonHandle& skeletonHandle) override {}

	virtual BonesHandle createBones(const uint32 maxNumberOfBones) override { return {0,1}; }
	virtual void destroy(const BonesHandle& bonesHandle) override {}

	virtual void attach(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const BonesHandle& bonesHandle) override {}
	virtual void detach(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const BonesHandle& bonesHandle) override {}

	virtual void attachBoneAttachment(
		const RenderSceneHandle& renderSceneHandle,
		const RenderableHandle& renderableHandle,
		const BonesHandle& bonesHandle,
		const glm::ivec4& boneIds,
		const glm::vec4& boneWeights
	) override {}
	virtual void detachBoneAttachment(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) override {}

	virtual TextureHandle createTexture2d(const ITexture* texture) override { return {0,1}; }
	
	virtual MaterialHandle createMaterial(const IPbrMaterial* pbrMaterial) override { return {0,1}; }
	
	virtual TerrainHandle createStaticTerrain(
			const IHeightMap* heightMap,
			const ISplatMap* splatMap,
			const IDisplacementMap* displacementMap
		) override { return {0,1}; }
		virtual void destroy(const TerrainHandle& terrainHandle) override {}

	virtual VertexShaderHandle createVertexShader(const std::string& data) override { return {0,1}; }
	virtual FragmentShaderHandle createFragmentShader(const std::string& data) override { return {0,1}; }
	virtual TessellationControlShaderHandle createTessellationControlShader(const std::string& data) override { return {0,1}; }
	virtual TessellationEvaluationShaderHandle createTessellationEvaluationShader(const std::string& data) override { return {0,1}; }
	virtual bool valid(const VertexShaderHandle& shaderHandle) const override { return true; }
	virtual bool valid(const FragmentShaderHandle& shaderHandle) const override { return true; }
	virtual bool valid(const TessellationControlShaderHandle& shaderHandle) const override { return true; }
	virtual bool valid(const TessellationEvaluationShaderHandle& shaderHandle) const override { return true; }
	virtual void destroyShader(const VertexShaderHandle& shaderHandle) override {}
	virtual void destroyShader(const FragmentShaderHandle& shaderHandle) override {}
	virtual void destroyShader(const TessellationControlShaderHandle& shaderHandle) override {}
	virtual void destroyShader(const TessellationEvaluationShaderHandle& shaderHandle) override {}
	virtual ShaderProgramHandle createShaderProgram(const VertexShaderHandle& vertexShaderHandle, const FragmentShaderHandle& fragmentShaderHandle) override { return {0,1}; }
	virtual ShaderProgramHandle createShaderProgram(
		const VertexShaderHandle& vertexShaderHandle,
		const TessellationControlShaderHandle& tessellationControlShaderHandle,
		const TessellationEvaluationShaderHandle& tessellationEvaluationShaderHandle,
		const FragmentShaderHandle& fragmentShaderHandle
	) override { return {0,1}; }
	virtual bool valid(const ShaderProgramHandle& shaderProgramHandle) const override { return true; }
	virtual void destroyShaderProgram(const ShaderProgramHandle& shaderProgramHandle) override {}
	
	virtual RenderableHandle createRenderable(
		const RenderSceneHandle& renderSceneHandle,
		const MeshHandle& meshHandle,
		const TextureHandle& textureHandle,
		const glm::vec3& position,
		const glm::quat& orientation,
		const glm::vec3& scale = glm::vec3(1.0f),
		const ShaderProgramHandle& shaderProgramHandle = ShaderProgramHandle()
	) override { return {0,1}; }
	virtual RenderableHandle createRenderable(
		const RenderSceneHandle& renderSceneHandle,
		const MeshHandle& meshHandle,
		const MaterialHandle& materialHandle,
		const glm::vec3& position,
		const glm::quat& orientation,
		const glm::vec3& scale = glm::vec3(1.0f)
	) override { return {0,1}; }
	virtual void destroy(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) override {}
	
	virtual TerrainRenderableHandle createTerrainRenderable(
		const RenderSceneHandle& renderSceneHandle,
		const TerrainHandle& terrainHandle
	) override { return {0,1}; }
	virtual void destroy(const RenderSceneHandle& renderSceneHandle, const TerrainRenderableHandle& terrainRenderableHandle) override {}
	
	virtual void rotate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::quat& quaternion, const TransformSpace& relativeTo = TransformSpace::TS_LOCAL) override {}
	virtual void rotate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 degrees, const glm::vec3& axis, const TransformSpace& relativeTo = TransformSpace::TS_LOCAL) override {}
	virtual void rotate(const CameraHandle& cameraHandle, const glm::quat& quaternion, const TransformSpace& relativeTo = TransformSpace::TS_LOCAL) override {}
	virtual void rotate(const CameraHandle& cameraHandle, const float32 degrees, const glm::vec3& axis, const TransformSpace& relativeTo = TransformSpace::TS_LOCAL) override {}
	
	virtual void rotation(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::quat& quaternion) override {}
	virtual void rotation(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 degrees, const glm::vec3& axis) override {}
	virtual glm::quat rotation(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) const override { return {}; }
	virtual void rotation(const CameraHandle& cameraHandle, const glm::quat& quaternion) override {}
	virtual void rotation(const CameraHandle& cameraHandle, const float32 degrees, const glm::vec3& axis) override {}
	virtual glm::quat rotation(const CameraHandle& cameraHandle) const override { return {}; }
	
	virtual void translate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 x, const float32 y, const float32 z) override {}
	virtual void translate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& trans) override {}
	virtual void translate(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const float32 x, const float32 y, const float32 z) override {}
	virtual void translate(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const glm::vec3& trans) override {}
	virtual void translate(const CameraHandle& cameraHandle, const float32 x, const float32 y, const float32 z) override {}
	virtual void translate(const CameraHandle& cameraHandle, const glm::vec3& trans) override {}
	
	virtual void scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 x, const float32 y, const float32 z) override {}
	virtual void scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& scale) override {}
	virtual void scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 scale) override {}
	virtual glm::vec3 scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) const override { return {}; }
	
	virtual void position(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 x, const float32 y, const float32 z) override {}
	virtual void position(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& position) override {}
	virtual glm::vec3 position(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) const override { return {}; }
	virtual void position(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const float32 x, const float32 y, const float32 z) override {}
	virtual void position(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const glm::vec3& position) override {}
	virtual glm::vec3 position(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle) const override { return {}; }
	virtual void position(const CameraHandle& cameraHandle, const float32 x, const float32 y, const float32 z) override {}
	virtual void position(const CameraHandle& cameraHandle, const glm::vec3& position) override {}
	virtual glm::vec3 position(const CameraHandle& cameraHandle) const override { return {}; }
	
	virtual void lookAt(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& lookAt) override {}
	virtual void lookAt(const CameraHandle& cameraHandle, const glm::vec3& lookAt) override {}
	
	virtual void assign(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const SkeletonHandle& skeletonHandle) override {}
	
	virtual void update(
		const RenderSceneHandle& renderSceneHandle,
		const RenderableHandle& renderableHandle,
		const BonesHandle& bonesHandle,
		const std::vector<glm::mat4>& transformations
	) override {}
	
	virtual void setMouseRelativeMode(const bool enabled) override {}
	virtual void setWindowGrab(const bool enabled) override {}
	virtual void setCursorVisible(const bool visible) override {}
	
	virtual void processEvents() override {}
	virtual void addEventListener(IEventListener* eventListener) override {}
	virtual void removeEventListener(IEventListener* eventListener) override {}

private:
	NullRenderer(const NullRenderer& other);
	
	utilities::Properties* properties_;
	fs::IFileSystem* fileSystem_;
	logger::ILogger* logger_;
};

}
}
}

#endif /* NULLRENDERER_H_ */
