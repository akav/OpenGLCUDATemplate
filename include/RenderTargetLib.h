//----------------------------------------------------------------------------------------------------------------------
/// @file RenderTargetLib.h
/// @class RenderTargetLib
/// @author Declan Russell
/// @date 28/04/2015
/// @version 1.0
/// @brief Singleton class for creating and storing render targets in a library
//----------------------------------------------------------------------------------------------------------------------


#ifndef RENDERTARGETLIB_H
#define RENDERTARGETLIB_H

#include <map>
#include <string>

#include "FrameBuffer.h"
#include "RenderBuffer.h"

class RenderTargetLib
{
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief add a render buffer to our library
    /// @param _name - the name of our render buffer
    //----------------------------------------------------------------------------------------------------------------------
    RenderBuffer * addRenderBuffer(std::string _name, GLenum _internalformat, GLenum _attachment, GLsizei _width, GLsizei _height);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief add a frame buffer to our library
    //----------------------------------------------------------------------------------------------------------------------
    FrameBuffer * addFrameBuffer(std::string _name);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief returns an instance of our render target library
    //----------------------------------------------------------------------------------------------------------------------
    static RenderTargetLib *getInstance();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief gets a frame buffer from our library
    //----------------------------------------------------------------------------------------------------------------------
    FrameBuffer * getFrameBuffer(const std::string &_name);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief gets a frame buffer from our library
    //----------------------------------------------------------------------------------------------------------------------
    FrameBuffer * getFrameBuffer(const char *_name);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief gets a render buffer from our library
    //----------------------------------------------------------------------------------------------------------------------
    RenderBuffer * getRenderBuffer(const std::string &_name);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief gets a render buffer from our library
    //----------------------------------------------------------------------------------------------------------------------
    RenderBuffer * getRenderBuffer(const char *_name);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Deletes our library
    //----------------------------------------------------------------------------------------------------------------------
    inline void destroy(){ delete m_instance; }
    //----------------------------------------------------------------------------------------------------------------------
private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our destructor. Removes all render targets from library
    //----------------------------------------------------------------------------------------------------------------------
    ~RenderTargetLib();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our static instance of our render target library
    //----------------------------------------------------------------------------------------------------------------------
    static RenderTargetLib* m_instance;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our default constructor. Don't want this to be accessable as this is a singleton class
    //----------------------------------------------------------------------------------------------------------------------
    RenderTargetLib(){}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the current frame buffer in use
    //----------------------------------------------------------------------------------------------------------------------
    FrameBuffer *m_currentFramebuffer;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the current frame buffer in use name
    //----------------------------------------------------------------------------------------------------------------------
    std::string m_currentFramebufferName;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the current render buffer in use
    //----------------------------------------------------------------------------------------------------------------------
    RenderBuffer *m_currentRenderbuffer;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the current render buffer in use name
    //----------------------------------------------------------------------------------------------------------------------
    std::string m_currentRenderbufferName;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief mip map for storing our render buffers
    //----------------------------------------------------------------------------------------------------------------------
    std::map<std::string,RenderBuffer*> m_renderBuffers;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief mip map for storing our frame buffers
    //----------------------------------------------------------------------------------------------------------------------
    std::map<std::string,FrameBuffer*> m_frameBuffers;
    //----------------------------------------------------------------------------------------------------------------------

};

#endif // RENDERTARGETLIB_H