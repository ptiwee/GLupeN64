#include "GLideN64_mupenplus.h"
#include <stdio.h>
#include <libretro_private.h>

#include "../GLideN64.h"
#include "../OpenGL.h"
#include "../gDP.h"
#include "../Config.h"
#include "../Log.h"

#ifndef EGL
#if !defined(OS_WINDOWS) || defined(GLES2) || defined(GLES3) || defined(GLES3_1)

void initGLFunctions()
{
}
#endif
#endif

class OGLVideoMupenPlus : public OGLVideo
{
public:
	OGLVideoMupenPlus() {}

private:
	void _setAttributes();
	void _getDisplaySize();

	virtual bool _start();
	virtual void _stop();
	virtual void _swapBuffers();
	virtual void _saveScreenshot();
	virtual bool _resizeWindow();
	virtual void _changeWindow();
};

OGLVideo & OGLVideo::get()
{
	static OGLVideoMupenPlus video;
	return video;
}

bool OGLVideoMupenPlus::_start()
{
	m_bFullscreen = 1;
	m_screenWidth = 640;
	m_screenHeight = 480;
	_setBufferSize();

	LOG(LOG_VERBOSE, "[gles2GlideN64]: Create setting videomode %dx%d\n", m_screenWidth, m_screenHeight);

	return true;
}

void OGLVideoMupenPlus::_stop()
{
}

void OGLVideoMupenPlus::_swapBuffers()
{
	retro_return(true);
}

void OGLVideoMupenPlus::_saveScreenshot()
{
}

bool OGLVideoMupenPlus::_resizeWindow()
{
	m_bFullscreen = false;
	m_width = m_screenWidth = m_resizeWidth;
	m_height = m_screenHeight = m_resizeHeight;

	_setBufferSize();
	isGLError(); // reset GL error.
	return true;
}

void OGLVideoMupenPlus::_changeWindow()
{
}