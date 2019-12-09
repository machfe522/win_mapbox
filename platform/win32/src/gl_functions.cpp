#include <mbgl/platform/gl_functions.hpp>

#define GL_GLEXT_PROTOTYPES

#include <Windows.h>
#include <GL/gl.h>



namespace mbgl {
	namespace platform {

		struct OpenGLModule {
			static OpenGLModule& CurrentContext()
			{
				static OpenGLModule sModule;
				return sModule;
			}

			OpenGLModule()
			{
				m_hModule = LoadLibraryA("opengl32.dll");
				if (!m_hModule)
				{

				}
			}

			~OpenGLModule()
			{
				FreeLibrary(m_hModule);
			}

			void* Functions(const char* szfunc)
			{
				void* pProcAddr = GetProcAddress(m_hModule, szfunc);
				if (pProcAddr != nullptr)
				{
					return pProcAddr;
				}

				pProcAddr = wglGetProcAddress(szfunc);
				if (pProcAddr != nullptr)
				{
					return pProcAddr;
				}

				return nullptr;
			}

			HMODULE m_hModule;

		};


#define MGCL(name)	(decltype(name))OpenGLModule::CurrentContext().Functions(#name)

		void(*const glActiveTexture)(GLenum) = [](auto... args) {
			(MGCL(glActiveTexture))(args...);
		};
		void(*const glAttachShader)(GLuint, GLuint) = [](auto... args) {
			(MGCL(glAttachShader))(args...);
		};
		void(*const glBindAttribLocation)(GLuint, GLuint, const GLchar *) = [](auto... args) {
			(MGCL(glBindAttribLocation))(args...);
		};
		void(*const glBindBuffer)(GLenum, GLuint) = [](auto... args) {
			(MGCL(glBindBuffer))(args...);
		};
		void(*const glBindFramebuffer)(GLenum, GLuint) = [](auto... args) {
			(MGCL(glBindFramebuffer))(args...);
		};
		void(*const glBindRenderbuffer)(GLenum, GLuint) = [](auto... args) {
			(MGCL(glBindRenderbuffer))(args...);
		};
		void(*const glBindTexture)(GLenum, GLuint) = [](auto... args) {
			(MGCL(glBindTexture))(args...);
		};
		void(*const glBlendColor)(GLfloat, GLfloat, GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glBlendColor))(args...);
		};
		void(*const glBlendEquation)(GLenum) = [](auto... args) {
			(MGCL(glBlendEquation))(args...);
		};
		void(*const glBlendEquationSeparate)(GLenum, GLenum) = [](auto... args) {
			(MGCL(glBlendEquationSeparate))(args...);
		};
		void(*const glBlendFunc)(GLenum, GLenum) = [](auto... args) {
			(MGCL(glBlendFunc))(args...);
		};
		void(*const glBlendFuncSeparate)(GLenum, GLenum, GLenum, GLenum) = [](auto... args) {
			(MGCL(glBlendFuncSeparate))(args...);
		};
		void(*const glBufferData)(GLenum, GLsizeiptr, const void *, GLenum) = [](auto... args) {
			(MGCL(glBufferData))(args...);
		};
		void(*const glBufferSubData)(GLenum, GLintptr, GLsizeiptr, const void *) = [](auto... args) {
			(MGCL(glBufferSubData))(args...);
		};
		GLenum(*const glCheckFramebufferStatus)(GLenum) = [](auto... args) {
			return (MGCL(glCheckFramebufferStatus))(args...);
		};
		void(*const glClear)(GLbitfield) = [](auto... args) {
			(MGCL(glClear))(args...);
		};
		void(*const glClearColor)(GLfloat, GLfloat, GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glClearColor))(args...);
		};
		void(*const glClearDepthf)(GLfloat) = [](auto... args) {
			(MGCL(glClearDepthf))(args...);
		};
		void(*const glClearStencil)(GLint) = [](auto... args) {
			(MGCL(glClearStencil))(args...);
		};
		void(*const glColorMask)(GLboolean, GLboolean, GLboolean, GLboolean) = [](auto... args) {
			(MGCL(glColorMask))(args...);
		};
		void(*const glCompileShader)(GLuint) = [](auto... args) {
			(MGCL(glCompileShader))(args...);
		};
		void(*const glCompressedTexImage2D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *) = [](auto... args) {
			(MGCL(glCompressedTexImage2D))(args...);
		};
		void(*const glCompressedTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *) = [](auto... args) {
			(MGCL(glCompressedTexSubImage2D))(args...);
		};
		void(*const glCopyTexImage2D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint) = [](auto... args) {
			(MGCL(glCopyTexImage2D))(args...);
		};
		void(*const glCopyTexSubImage2D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = [](auto... args) {
			(MGCL(glCopyTexSubImage2D))(args...);
		};
		GLuint(*const glCreateProgram)() = [](auto... args) {
			return(MGCL(glCreateProgram))(args...);
		};
		GLuint(*const glCreateShader)(GLenum) = [](auto... args) {
			return(MGCL(glCreateShader))(args...);
		};
		void(*const glCullFace)(GLenum) = [](auto... args) {
			(MGCL(glCullFace))(args...);
		};
		void(*const glDeleteBuffers)(GLsizei, const GLuint *) = [](auto... args) {
			(MGCL(glDeleteBuffers))(args...);
		};
		void(*const glDeleteFramebuffers)(GLsizei, const GLuint *) = [](auto... args) {
			(MGCL(glDeleteFramebuffers))(args...);
		};
		void(*const glDeleteProgram)(GLuint) = [](auto... args) {
			(MGCL(glDeleteProgram))(args...);
		};
		void(*const glDeleteRenderbuffers)(GLsizei, const GLuint *) = [](auto... args) {
			(MGCL(glDeleteRenderbuffers))(args...);
		};
		void(*const glDeleteShader)(GLuint) = [](auto... args) {
			(MGCL(glDeleteShader))(args...);
		};
		void(*const glDeleteTextures)(GLsizei, const GLuint *) = [](auto... args) {
			(MGCL(glDeleteTextures))(args...);
		};
		void(*const glDepthFunc)(GLenum) = [](auto... args) {
			(MGCL(glDepthFunc))(args...);
		};
		void(*const glDepthMask)(GLboolean) = [](auto... args) {
			(MGCL(glDepthMask))(args...);
		};
		void(*const glDepthRangef)(GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glDepthRangef))(args...);
		};
		void(*const glDetachShader)(GLuint, GLuint) = [](auto... args) {
			(MGCL(glDetachShader))(args...);
		};
		void(*const glDisable)(GLenum) = [](auto... args) {
			(MGCL(glDisable))(args...);
		};
		void(*const glDisableVertexAttribArray)(GLuint) = [](auto... args) {
			(MGCL(glDisableVertexAttribArray))(args...);
		};
		void(*const glDrawArrays)(GLenum, GLint, GLsizei) = [](auto... args) {
			(MGCL(glDrawArrays))(args...);
		};
		void(*const glDrawElements)(GLenum, GLsizei, GLenum, const void *) = [](auto... args) {
			(MGCL(glDrawElements))(args...);
		};
		void(*const glEnable)(GLenum) = [](auto... args) {
			(MGCL(glEnable))(args...);
		};
		void(*const glEnableVertexAttribArray)(GLuint) = [](auto... args) {
			(MGCL(glEnableVertexAttribArray))(args...);
		};
		void(*const glFinish)() = [](auto... args) {
			(MGCL(glFinish))(args...);
		};
		void(*const glFlush)() = [](auto... args) {
			(MGCL(glFlush))(args...);
		};
		void(*const glFramebufferRenderbuffer)(GLenum, GLenum, GLenum, GLuint) = [](auto... args) {
			(MGCL(glFramebufferRenderbuffer))(args...);
		};
		void(*const glFramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint, GLint) = [](auto... args) {
			(MGCL(glFramebufferTexture2D))(args...);
		};
		void(*const glFrontFace)(GLenum) = [](auto... args) {
			(MGCL(glFrontFace))(args...);
		};
		void(*const glGenBuffers)(GLsizei, GLuint *) = [](auto... args) {
			(MGCL(glGenBuffers))(args...);
		};
		void(*const glGenerateMipmap)(GLenum) = [](auto... args) {
			(MGCL(glGenerateMipmap))(args...);
		};
		void(*const glGenFramebuffers)(GLsizei, GLuint *) = [](auto... args) {
			(MGCL(glGenFramebuffers))(args...);
		};
		void(*const glGenRenderbuffers)(GLsizei, GLuint *) = [](auto... args) {
			(MGCL(glGenRenderbuffers))(args...);
		};
		void(*const glGenTextures)(GLsizei, GLuint *) = [](auto... args) {
			(MGCL(glGenTextures))(args...);
		};
		void(*const glGetActiveAttrib)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *) = [](auto... args) {
			(MGCL(glGetActiveAttrib))(args...);
		};
		void(*const glGetActiveUniform)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *) = [](auto... args) {
			(MGCL(glGetActiveUniform))(args...);
		};
		void(*const glGetAttachedShaders)(GLuint, GLsizei, GLsizei *, GLuint *) = [](auto... args) {
			(MGCL(glGetAttachedShaders))(args...);
		};
		GLint(*const glGetAttribLocation)(GLuint, const GLchar *) = [](auto... args) {
			return(MGCL(glGetAttribLocation))(args...);
		};
		void(*const glGetBooleanv)(GLenum, GLboolean *) = [](auto... args) {
			(MGCL(glGetBooleanv))(args...);
		};
		void(*const glGetBufferParameteriv)(GLenum, GLenum, GLint *) = [](auto... args) {
			(MGCL(glGetBufferParameteriv))(args...);
		};
		GLenum(*const glGetError)() = [](auto... args) {
			return(MGCL(glGetError))(args...);
		};
		void(*const glGetFloatv)(GLenum, GLfloat *) = [](auto... args) {
			(MGCL(glGetFloatv))(args...);
		};
		void(*const glGetFramebufferAttachmentParameteriv)(GLenum, GLenum, GLenum, GLint *) = [](auto... args) {
			(MGCL(glGetFramebufferAttachmentParameteriv))(args...);
		};
		void(*const glGetIntegerv)(GLenum, GLint *) = [](auto... args) {
			(MGCL(glGetIntegerv))(args...);
		};
		void(*const glGetProgramInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *) = [](auto... args) {
			(MGCL(glGetProgramInfoLog))(args...);
		};;
		void(*const glGetProgramiv)(GLuint, GLenum, GLint *) = [](auto... args) {
			(MGCL(glGetProgramiv))(args...);
		};
		void(*const glGetRenderbufferParameteriv)(GLenum, GLenum, GLint *) = [](auto... args) {
			(MGCL(glGetRenderbufferParameteriv))(args...);
		};
		void(*const glGetShaderInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *) = [](auto... args) {
			(MGCL(glGetShaderInfoLog))(args...);
		};
		void(*const glGetShaderiv)(GLuint, GLenum, GLint *) = [](auto... args) {
			(MGCL(glGetShaderiv))(args...);
		};
		void(*const glGetShaderSource)(GLuint, GLsizei, GLsizei *, GLchar *) = [](auto... args) {
			(MGCL(glGetShaderSource))(args...);
		};
		const GLubyte *(*glGetString)(GLenum) = [](auto... args) {
			return(MGCL(glGetString))(args...);
		};
		void(*const glGetTexParameterfv)(GLenum, GLenum, GLfloat *) = [](auto... args) {
			(MGCL(glGetTexParameterfv))(args...);
		};
		void(*const glGetTexParameteriv)(GLenum, GLenum, GLint *) = [](auto... args) {
			(MGCL(glGetTexParameteriv))(args...);
		};
		void(*const glGetUniformfv)(GLuint, GLint, GLfloat *) = [](auto... args) {
			(MGCL(glGetUniformfv))(args...);
		};
		void(*const glGetUniformiv)(GLuint, GLint, GLint *) = [](auto... args) {
			(MGCL(glGetUniformiv))(args...);
		};
		GLint(*const glGetUniformLocation)(GLuint, const GLchar *) = [](auto... args) {
			return (MGCL(glGetUniformLocation))(args...);
		};
		void(*const glGetVertexAttribfv)(GLuint, GLenum, GLfloat *) = [](auto... args) {
			(MGCL(glGetVertexAttribfv))(args...);
		};
		void(*const glGetVertexAttribiv)(GLuint, GLenum, GLint *) = [](auto... args) {
			(MGCL(glGetVertexAttribiv))(args...);
		};
		void(*const glGetVertexAttribPointerv)(GLuint, GLenum, void **) = [](auto... args) {
			(MGCL(glGetVertexAttribPointerv))(args...);
		};
		void(*const glHint)(GLenum, GLenum) = [](auto... args) {
			return(MGCL(glHint))(args...);
		};
		GLboolean(*const glIsBuffer)(GLuint) = [](auto... args) {
			return(MGCL(glIsBuffer))(args...);
		};
		GLboolean(*const glIsEnabled)(GLenum) = [](auto... args) {
			return(MGCL(glIsEnabled))(args...);
		};
		GLboolean(*const glIsFramebuffer)(GLuint) = [](auto... args) {
			return(MGCL(glIsFramebuffer))(args...);
		};
		GLboolean(*const glIsProgram)(GLuint) = [](auto... args) {
			return(MGCL(glIsProgram))(args...);
		};
		GLboolean(*const glIsRenderbuffer)(GLuint) = [](auto... args) {
			return(MGCL(glIsRenderbuffer))(args...);
		};
		GLboolean(*const glIsShader)(GLuint) = [](auto... args) {
			return(MGCL(glIsShader))(args...);
		};
		GLboolean(*const glIsTexture)(GLuint) = [](auto... args) {
			return(MGCL(glIsTexture))(args...);
		};
		void(*const glLineWidth)(GLfloat) = [](auto... args) {
			(MGCL(glLineWidth))(args...);
		};
		void(*const glLinkProgram)(GLuint) = [](auto... args) {
			(MGCL(glLinkProgram))(args...);
		};
		void(*const glPixelStorei)(GLenum, GLint) = [](auto... args) {
			(MGCL(glPixelStorei))(args...);
		};
		void(*const glPolygonOffset)(GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glPolygonOffset))(args...);
		};
		void(*const glReadPixels)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void *) = [](auto... args) {
			(MGCL(glReadPixels))(args...);
		};
		void(*const glRenderbufferStorage)(GLenum, GLenum, GLsizei, GLsizei) = [](auto... args) {
			(MGCL(glRenderbufferStorage))(args...);
		};
		void(*const glSampleCoverage)(GLfloat, GLboolean) = [](auto... args) {
			(MGCL(glSampleCoverage))(args...);
		};
		void(*const glScissor)(GLint, GLint, GLsizei, GLsizei) = [](auto... args) {
			(MGCL(glScissor))(args...);
		};
		void(*const glShaderSource)(GLuint, GLsizei, const GLchar * const*, const GLint *) = [](auto... args) {
			(MGCL(glShaderSource))(args...);
		};
		void(*const glStencilFunc)(GLenum, GLint, GLuint) = [](auto... args) {
			(MGCL(glStencilFunc))(args...);
		};
		void(*const glStencilFuncSeparate)(GLenum, GLenum, GLint, GLuint) = [](auto... args) {
			(MGCL(glStencilFuncSeparate))(args...);
		};
		void(*const glStencilMask)(GLuint) = [](auto... args) {
			(MGCL(glStencilMask))(args...);
		};
		void(*const glStencilMaskSeparate)(GLenum, GLuint) = [](auto... args) {
			(MGCL(glStencilMaskSeparate))(args...);
		};
		void(*const glStencilOp)(GLenum, GLenum, GLenum) = [](auto... args) {
			(MGCL(glStencilOp))(args...);
		};
		void(*const glStencilOpSeparate)(GLenum, GLenum, GLenum, GLenum) = [](auto... args) {
			(MGCL(glStencilOpSeparate))(args...);
		};
		void(*const glTexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *) = [](auto... args) {
			(MGCL(glTexImage2D))(args...);
		};
		void(*const glTexParameterf)(GLenum, GLenum, GLfloat) = [](auto... args) {
			(MGCL(glTexParameterf))(args...);
		};
		void(*const glTexParameterfv)(GLenum, GLenum, const GLfloat *) = [](auto... args) {
			(MGCL(glTexParameterfv))(args...);
		};
		void(*const glTexParameteri)(GLenum, GLenum, GLint) = [](auto... args) {
			(MGCL(glTexParameteri))(args...);
		};
		void(*const glTexParameteriv)(GLenum, GLenum, const GLint *) = [](auto... args) {
			(MGCL(glTexParameteriv))(args...);
		};
		void(*const glTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *) = [](auto... args) {
			(MGCL(glTexSubImage2D))(args...);
		};
		void(*const glUniform1f)(GLint, GLfloat) = [](auto... args) {
			(MGCL(glUniform1f))(args...);
		};
		void(*const glUniform1fv)(GLint, GLsizei, const GLfloat *) = [](auto... args) {
			(MGCL(glUniform1fv))(args...);
		};
		void(*const glUniform1i)(GLint, GLint) = [](auto... args) {
			(MGCL(glUniform1i))(args...);
		};
		void(*const glUniform1iv)(GLint, GLsizei, const GLint *) = [](auto... args) {
			(MGCL(glUniform1iv))(args...);
		};
		void(*const glUniform2f)(GLint, GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glUniform2f))(args...);
		};
		void(*const glUniform2fv)(GLint, GLsizei, const GLfloat *) = [](auto... args) {
			(MGCL(glUniform2fv))(args...);
		};
		void(*const glUniform2i)(GLint, GLint, GLint) = [](auto... args) {
			(MGCL(glUniform2i))(args...);
		};
		void(*const glUniform2iv)(GLint, GLsizei, const GLint *) = [](auto... args) {
			(MGCL(glUniform2iv))(args...);
		};
		void(*const glUniform3f)(GLint, GLfloat, GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glUniform3f))(args...);
		};
		void(*const glUniform3fv)(GLint, GLsizei, const GLfloat *) = [](auto... args) {
			(MGCL(glUniform3fv))(args...);
		};
		void(*const glUniform3i)(GLint, GLint, GLint, GLint) = [](auto... args) {
			(MGCL(glUniform3i))(args...);
		};
		void(*const glUniform3iv)(GLint, GLsizei, const GLint *) = [](auto... args) {
			(MGCL(glUniform3iv))(args...);
		};
		void(*const glUniform4f)(GLint, GLfloat, GLfloat, GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glUniform4f))(args...);
		};
		void(*const glUniform4fv)(GLint, GLsizei, const GLfloat *) = [](auto... args) {
			(MGCL(glUniform4fv))(args...);
		};
		void(*const glUniform4i)(GLint, GLint, GLint, GLint, GLint) = [](auto... args) {
			(MGCL(glUniform4i))(args...);
		};
		void(*const glUniform4iv)(GLint, GLsizei, const GLint *) = [](auto... args) {
			(MGCL(glUniform4iv))(args...);
		};
		void(*const glUniformMatrix2fv)(GLint, GLsizei, GLboolean, const GLfloat *) = [](auto... args) {
			(MGCL(glUniformMatrix2fv))(args...);
		};
		void(*const glUniformMatrix3fv)(GLint, GLsizei, GLboolean, const GLfloat *) = [](auto... args) {
			(MGCL(glUniformMatrix3fv))(args...);
		};
		void(*const glUniformMatrix4fv)(GLint, GLsizei, GLboolean, const GLfloat *) = [](auto... args) {
			(MGCL(glUniformMatrix4fv))(args...);
		};
		void(*const glUseProgram)(GLuint) = [](auto... args) {
			(MGCL(glUseProgram))(args...);
		};
		void(*const glValidateProgram)(GLuint) = [](auto... args) {
			(MGCL(glValidateProgram))(args...);
		};
		void(*const glVertexAttrib1f)(GLuint, GLfloat) = [](auto... args) {
			(MGCL(glVertexAttrib1f))(args...);
		};
		void(*const glVertexAttrib1fv)(GLuint, const GLfloat *) = [](auto... args) {
			(MGCL(glVertexAttrib1fv))(args...);
		};
		void(*const glVertexAttrib2f)(GLuint, GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glVertexAttrib2f))(args...);
		};
		void(*const glVertexAttrib2fv)(GLuint, const GLfloat *) = [](auto... args) {
			(MGCL(glVertexAttrib2fv))(args...);
		};
		void(*const glVertexAttrib3f)(GLuint, GLfloat, GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glVertexAttrib3f))(args...);
		};
		void(*const glVertexAttrib3fv)(GLuint, const GLfloat *) = [](auto... args) {
			(MGCL(glVertexAttrib3fv))(args...);
		};
		void(*const glVertexAttrib4f)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glVertexAttrib4f))(args...);
		};
		void(*const glVertexAttrib4fv)(GLuint, const GLfloat *) = [](auto... args) {
			(MGCL(glVertexAttrib4fv))(args...);
		};
		void(*const glVertexAttribPointer)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *) = [](auto... args) {
			(MGCL(glVertexAttribPointer))(args...);
		};
		void(*const glViewport)(GLint, GLint, GLsizei, GLsizei) = [](auto... args) {
			(MGCL(glViewport))(args...);
		};

		void(*const glDrawPixels)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = [](auto... args) {
			(MGCL(glDrawPixels))(args...);
		};
		void(*const glGetDoublev)(GLenum, GLdouble *) = [](auto... args) {
			(MGCL(glGetDoublev))(args...);
		};
		void(*const glPixelTransferf)(GLenum, GLfloat) = [](auto... args) {
			(MGCL(glPixelTransferf))(args...);
		};
		void(*const glPixelZoom)(GLfloat, GLfloat) = [](auto... args) {
			(MGCL(glPixelZoom))(args...);
		};
		void(*const glPointSize)(GLfloat) = [](auto... args) {
			(MGCL(glPointSize))(args...);
		};
		void(*const glRasterPos4d)(GLdouble, GLdouble, GLdouble, GLdouble) = [](auto... args) {
			(MGCL(glRasterPos4d))(args...);
		};


	}  // namespace platform
}  // namespace mbgl
