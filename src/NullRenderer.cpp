#include "NullRenderer.hpp"

namespace ice_engine
{
namespace graphics
{
namespace null_renderer
{

NullRenderer::NullRenderer(
	utilities::Properties* properties,
	fs::IFileSystem* fileSystem,
	logger::ILogger* logger
)
	:
	properties_(properties),
	fileSystem_(fileSystem),
	logger_(logger)
{
	
}

NullRenderer::~NullRenderer()
{
}

void NullRenderer::setViewport(const uint32 width, const uint32 height) {}
glm::uvec2 NullRenderer::getViewport() const { return glm::uvec2(); }

glm::mat4 NullRenderer::getModelMatrix() const { return glm::mat4(); }
glm::mat4 NullRenderer::getViewMatrix() const { return glm::mat4(); }
glm::mat4 NullRenderer::getProjectionMatrix() const { return glm::mat4(); }

void NullRenderer::beginRender() {}
void NullRenderer::render(const RenderSceneHandle& renderSceneHandle) {}
void NullRenderer::renderLine(const glm::vec3& from, const glm::vec3& to, const glm::vec3& color) {}
void NullRenderer::renderLines(const std::vector<std::tuple<glm::vec3, glm::vec3, glm::vec3>>& lineData) {}
void NullRenderer::endRender() {}

RenderSceneHandle NullRenderer::createRenderScene() { return RenderSceneHandle(1); }
void NullRenderer::destroyRenderScene(const RenderSceneHandle& renderSceneHandle) {}

CameraHandle NullRenderer::createCamera(const glm::vec3& position, const glm::vec3& lookAt) { return CameraHandle(1); }

PointLightHandle NullRenderer::createPointLight(const RenderSceneHandle& renderSceneHandle, const glm::vec3& position) { return PointLightHandle(1); }

MeshHandle NullRenderer::createStaticMesh(
	const std::vector<glm::vec3>& vertices,
	const std::vector<uint32>& indices,
	const std::vector<glm::vec4>& colors,
	const std::vector<glm::vec3>& normals,
	const std::vector<glm::vec2>& textureCoordinates
) { return MeshHandle(1); }

MeshHandle NullRenderer::createStaticMesh(const model::Mesh& mesh) { return MeshHandle(1); }

MeshHandle NullRenderer::createAnimatedMesh(
	const std::vector<glm::vec3>& vertices,
	const std::vector<uint32>& indices,
	const std::vector<glm::vec4>& colors,
	const std::vector<glm::vec3>& normals,
	const std::vector<glm::vec2>& textureCoordinates,
	const std::vector<glm::ivec4>& boneIds,
	const std::vector<glm::vec4>& boneWeights
) { return MeshHandle(1); }

MeshHandle NullRenderer::createDynamicMesh(
	const std::vector<glm::vec3>& vertices,
	const std::vector<uint32>& indices,
	const std::vector<glm::vec4>& colors,
	const std::vector<glm::vec3>& normals,
	const std::vector<glm::vec2>& textureCoordinates
) { return MeshHandle(1); }

SkeletonHandle NullRenderer::createSkeleton(const uint32 numberOfBones) { return SkeletonHandle(1); }

TextureHandle NullRenderer::createTexture2d(const IImage* image) { return TextureHandle(1); }

MaterialHandle NullRenderer::createMaterial(const IPbrMaterial* pbrMaterial) { return MaterialHandle(1); }

VertexShaderHandle NullRenderer::createVertexShader(const std::string& data) { return VertexShaderHandle(1); }
FragmentShaderHandle NullRenderer::createFragmentShader(const std::string& data) { return FragmentShaderHandle(1); }
TessellationControlShaderHandle NullRenderer::createTessellationControlShader(const std::string& data) { return TessellationControlShaderHandle(1); }
TessellationEvaluationShaderHandle NullRenderer::createTessellationEvaluationShader(const std::string& data) { return TessellationEvaluationShaderHandle(1); }
bool NullRenderer::valid(const VertexShaderHandle& shaderHandle) const { return (shaderHandle ? true : false); }
bool NullRenderer::valid(const FragmentShaderHandle& shaderHandle) const { return (shaderHandle ? true : false); }
bool NullRenderer::valid(const TessellationControlShaderHandle& shaderHandle) const { return (shaderHandle ? true : false); }
bool NullRenderer::valid(const TessellationEvaluationShaderHandle& shaderHandle) const { return (shaderHandle ? true : false); }
void NullRenderer::destroyShader(const VertexShaderHandle& shaderHandle) {}
void NullRenderer::destroyShader(const FragmentShaderHandle& shaderHandle) {}
void NullRenderer::destroyShader(const TessellationControlShaderHandle& shaderHandle) {}
void NullRenderer::destroyShader(const TessellationEvaluationShaderHandle& shaderHandle) {}
ShaderProgramHandle NullRenderer::createShaderProgram(const VertexShaderHandle& vertexShaderHandle, const FragmentShaderHandle& fragmentShaderHandle) { return ShaderProgramHandle(1); }
ShaderProgramHandle NullRenderer::createShaderProgram(
	const VertexShaderHandle& vertexShaderHandle,
	const TessellationControlShaderHandle& tessellationControlShaderHandle,
	const TessellationEvaluationShaderHandle& tessellationEvaluationShaderHandle,
	const FragmentShaderHandle& fragmentShaderHandle
) { return ShaderProgramHandle(1); }
bool NullRenderer::valid(const ShaderProgramHandle& shaderProgramHandle) const { return (shaderProgramHandle ? true : false); }
void NullRenderer::destroyShaderProgram(const ShaderProgramHandle& shaderProgramHandle) {}

RenderableHandle NullRenderer::createRenderable(const RenderSceneHandle& renderSceneHandle, const MeshHandle& meshHandle, const TextureHandle& textureHandle, const ShaderProgramHandle& shaderProgramHandle) { return RenderableHandle(1); }
RenderableHandle NullRenderer::createRenderable(const RenderSceneHandle& renderSceneHandle, const MeshHandle& meshHandle, const MaterialHandle& materialHandle) { return RenderableHandle(1); }
void NullRenderer::destroy(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) {}

TerrainHandle NullRenderer::createTerrain(
	const RenderSceneHandle& renderSceneHandle,
	const IHeightMap* heightMap,
	const ISplatMap* splatMap,
	const IDisplacementMap* displacementMap
) { return TerrainHandle(1); }
void NullRenderer::destroy(const RenderSceneHandle& renderSceneHandle, const TerrainHandle& terrainHandle) {}

void NullRenderer::rotate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::quat& quaternion, const TransformSpace& relativeTo) {}
void NullRenderer::rotate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 degrees, const glm::vec3& axis, const TransformSpace& relativeTo) {}
void NullRenderer::rotate(const CameraHandle& cameraHandle, const glm::quat& quaternion, const TransformSpace& relativeTo) {}
void NullRenderer::rotate(const CameraHandle& cameraHandle, const float32 degrees, const glm::vec3& axis, const TransformSpace& relativeTo) {}

void NullRenderer::rotation(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::quat& quaternion) {}
void NullRenderer::rotation(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 degrees, const glm::vec3& axis) {}
glm::quat NullRenderer::rotation(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) const { return glm::quat(); }
void NullRenderer::rotation(const CameraHandle& cameraHandle, const glm::quat& quaternion) {}
void NullRenderer::rotation(const CameraHandle& cameraHandle, const float32 degrees, const glm::vec3& axis) {}
glm::quat NullRenderer::rotation(const CameraHandle& cameraHandle) const { return glm::quat(); }

void NullRenderer::translate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 x, const float32 y, const float32 z) {}
void NullRenderer::translate(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& trans) {}
void NullRenderer::translate(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const float32 x, const float32 y, const float32 z) {}
void NullRenderer::translate(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const glm::vec3& trans) {}
void NullRenderer::translate(const CameraHandle& cameraHandle, const float32 x, const float32 y, const float32 z) {}
void NullRenderer::translate(const CameraHandle& cameraHandle, const glm::vec3& trans) {}

void NullRenderer::scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 x, const float32 y, const float32 z) {}
void NullRenderer::scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& scale) {}
void NullRenderer::scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 scale) {}
glm::vec3 NullRenderer::scale(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) const { return glm::vec3(); }

void NullRenderer::position(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const float32 x, const float32 y, const float32 z) {}
void NullRenderer::position(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& position) {}
glm::vec3 NullRenderer::position(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle) const { return glm::vec3(); }
void NullRenderer::position(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const float32 x, const float32 y, const float32 z) {}
void NullRenderer::position(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle, const glm::vec3& position) {}
glm::vec3 NullRenderer::position(const RenderSceneHandle& renderSceneHandle, const PointLightHandle& pointLightHandle) const { return glm::vec3(); }
void NullRenderer::position(const CameraHandle& cameraHandle, const float32 x, const float32 y, const float32 z) {}
void NullRenderer::position(const CameraHandle& cameraHandle, const glm::vec3& position) {}
glm::vec3 NullRenderer::position(const CameraHandle& cameraHandle) const { return glm::vec3(); }

void NullRenderer::lookAt(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const glm::vec3& lookAt) {}
void NullRenderer::lookAt(const CameraHandle& cameraHandle, const glm::vec3& lookAt) {}

void NullRenderer::assign(const RenderSceneHandle& renderSceneHandle, const RenderableHandle& renderableHandle, const SkeletonHandle& skeletonHandle) {}

void NullRenderer::update(const SkeletonHandle& skeletonHandle, const void* data, const uint32 size) {}

void NullRenderer::setMouseRelativeMode(const bool enabled) {}
void NullRenderer::setWindowGrab(const bool enabled) {}
void NullRenderer::setCursorVisible(const bool visible) {}

void NullRenderer::processEvents() {}
void NullRenderer::addEventListener(IEventListener* eventListener) {}
void NullRenderer::removeEventListener(IEventListener* eventListener) {}

}
}
}
