#ifndef NULLRENDERER_H_
#define NULLRENDERER_H_

#include <vector>

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
	NullRenderer(
		utilities::Properties* properties,
		fs::IFileSystem* fileSystem,
		logger::ILogger* logger
	);
	virtual ~NullRenderer();

	virtual void setViewport(const uint32 width, const uint32 height) override;
	virtual glm::uvec2 getViewport() const override;
	
	virtual glm::mat4 getModelMatrix() const override;
	virtual glm::mat4 getViewMatrix() const override;
	virtual glm::mat4 getProjectionMatrix() const override;
	
	virtual void beginRender() override;
	virtual void render(const RenderSceneHandle& renderSceneHandle) override;
	virtual void renderLine(const glm::vec3& from, const glm::vec3& to, const glm::vec3& color) override;
	virtual void renderLines(const std::vector<std::tuple<glm::vec3, glm::vec3, glm::vec3>>& lineData) override;
	virtual void endRender() override;
	
	virtual RenderSceneHandle createRenderScene() override;
	virtual void destroyRenderScene(const RenderSceneHandle& renderSceneHandle) override;
	
	virtual CameraHandle createCamera(const glm::vec3& position, const glm::vec3& lookAt = glm::vec3(0.0f, 0.0f, 0.0f)) override;
	
	virtual PointLightHandle createPointLight(const RenderSceneHandle& renderSceneHandle, const glm::vec3& position) override;
	
	virtual MeshHandle createStaticMesh(
		const std::vector<glm::vec3>& vertices,
		const std::vector<uint32>& indices,
		const std::vector<glm::vec4>& colors,
		const std::vector<glm::vec3>& normals,
		const std::vector<glm::vec2>& textureCoordinates
	) override;
	virtual MeshHandle createStaticMesh(const model::Mesh& mesh) override;
	virtual MeshHandle createAnimatedMesh(
		const std::vector<glm::vec3>& vertices,
		const std::vector<uint32>& indices,
		const std::vector<glm::vec4>& colors,
		const std::vector<glm::vec3>& normals,
		const std::vector<glm::vec2>& textureCoordinates,
		const std::vector<glm::ivec4>& boneIds,
		const std::vector<glm::vec4>& boneWeights
	) override;
	virtual MeshHandle createDynamicMesh(
		const std::vector<glm::vec3>& vertices,
		const std::vector<uint32>& indices,
		const std::vector<glm::vec4>& colors,
		const std::vector<glm::vec3>& normals,
		const std::vector<glm::vec2>& textureCoordinates
	) override;
	
	virtual SkeletonHandle createSkeleton(const uint32 numberOfBones) override;
	
	virtual TextureHandle createTexture2d(const IImage* image) override;
	
	virtual MaterialHandle createMaterial(const IPbrMaterial* pbrMaterial) override;
	
	virtual VertexShaderHandle createVertexShader(const std::string& data) override;
	virtual FragmentShaderHandle createFragmentShader(const std::string& data) override;
	virtual TessellationControlShaderHandle createTessellationControlShader(const std::string& data) override;
	virtual TessellationEvaluationShaderHandle createTessellationEvaluationShader(const std::string& data) override;
	virtual bool valid(const VertexShaderHandle& shaderHandle) const override;
	virtual bool valid(const FragmentShaderHandle& shaderHandle) const override;
	virtual bool valid(const TessellationControlShaderHandle& shaderHandle) const override;
	virtual bool valid(const TessellationEvaluationShaderHandle& shaderHandle) const override;
	virtual void destroyShader(const VertexShaderHandle& shaderHandle) override;
	virtual void destroyShader(const FragmentShaderHandle& shaderHandle) override;
	virtual void destroyShader(const TessellationControlShaderHandle& shaderHandle) override;
	virtual void destroyShader(const TessellationEvaluationShaderHandle& shaderHandle) override;
	virtual ShaderProgramHandle createShaderProgram(const VertexShaderHandle& vertexShaderHandle, const FragmentShaderHandle& fragmentShaderHandle) override;
	virtual ShaderProgramHandle createShaderProgram(
		const VertexShaderHandle& vertexShaderHandle,
		const TessellationControlShaderHandle& tessellationControlShaderHandle,
		const TessellationEvaluationShaderHandle& tessellationEvaluationShaderHandle,
		const FragmentShaderHandle& fragmentShaderHandle
	) override;
	virtual bool valid(const ShaderProgramHandle& shaderProgramHandle) const override;
	virtual void destroyShaderProgram(const ShaderProgramHandle& shaderProgramHandle) override;
	
	virtual RenderableHandle createRenderable(const RenderSceneHandle& renderSceneHandle, const MeshHandle& meshHandle, const TextureHandle& textureHandle, const ShaderProgramHandle& shaderProgramHandle = ShaderProgramHandle()) override;
	virtual RenderableHandle createRenderable(const RenderSceneHandle& renderSceneHandle, const MeshHandle& meshHandle, const MaterialHandle& materialHandle) override;
	virtual void destroy(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) override;
	
	virtual TerrainHandle createTerrain(
		const RenderSceneHandle& renderSceneHandle,
		const IHeightMap* heightMap,
		const ISplatMap* splatMap,
		const IDisplacementMap* displacementMap
	) override;
	virtual void destroy(const RenderSceneHandle& renderSceneHandle, const TerrainHandle& terrainHandle) override;
	
	virtual void rotate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::quat& quaternion, const TransformSpace& relativeTo = TransformSpace::TS_LOCAL) override;
	virtual void rotate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 degrees, const glm::vec3& axis, const TransformSpace& relativeTo = TransformSpace::TS_LOCAL) override;
	virtual void rotate(const CameraHandle& cameraHandle, const glm::quat& quaternion, const TransformSpace& relativeTo = TransformSpace::TS_LOCAL) override;
	virtual void rotate(const CameraHandle& cameraHandle, const float32 degrees, const glm::vec3& axis, const TransformSpace& relativeTo = TransformSpace::TS_LOCAL) override;
	
	virtual void rotation(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::quat& quaternion) override;
	virtual void rotation(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 degrees, const glm::vec3& axis) override;
	virtual glm::quat rotation(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) const override;
	virtual void rotation(const CameraHandle& cameraHandle, const glm::quat& quaternion) override;
	virtual void rotation(const CameraHandle& cameraHandle, const float32 degrees, const glm::vec3& axis) override;
	virtual glm::quat rotation(const CameraHandle& cameraHandle) const override;
	
	virtual void translate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 x, const float32 y, const float32 z) override;
	virtual void translate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& trans) override;
	virtual void translate(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const float32 x, const float32 y, const float32 z) override;
	virtual void translate(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const glm::vec3& trans) override;
	virtual void translate(const CameraHandle& cameraHandle, const float32 x, const float32 y, const float32 z) override;
	virtual void translate(const CameraHandle& cameraHandle, const glm::vec3& trans) override;
	
	virtual void scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 x, const float32 y, const float32 z) override;
	virtual void scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& scale) override;
	virtual void scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 scale) override;
	virtual glm::vec3 scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) const override;
	
	virtual void position(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 x, const float32 y, const float32 z) override;
	virtual void position(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& position) override;
	virtual glm::vec3 position(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) const override;
	virtual void position(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const float32 x, const float32 y, const float32 z) override;
	virtual void position(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const glm::vec3& position) override;
	virtual glm::vec3 position(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle) const override;
	virtual void position(const CameraHandle& cameraHandle, const float32 x, const float32 y, const float32 z) override;
	virtual void position(const CameraHandle& cameraHandle, const glm::vec3& position) override;
	virtual glm::vec3 position(const CameraHandle& cameraHandle) const override;
	
	virtual void lookAt(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& lookAt) override;
	virtual void lookAt(const CameraHandle& cameraHandle, const glm::vec3& lookAt) override;
	
	virtual void assign(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const SkeletonHandle& skeletonHandle) override;
	
	virtual void update(const SkeletonHandle& skeletonHandle, const void* data, const uint32 size) override;
	
	virtual void setMouseRelativeMode(const bool enabled) override;
	virtual void setWindowGrab(const bool enabled) override;
	virtual void setCursorVisible(const bool visible) override;
	
	virtual void processEvents() override;
	virtual void addEventListener(IEventListener* eventListener) override;
	virtual void removeEventListener(IEventListener* eventListener) override;

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
