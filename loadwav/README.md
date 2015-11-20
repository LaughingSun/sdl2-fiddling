Working with wav files and the sdl_audio module
===============================================

I still have some doubts as to playing multiple wavs and what is modular as apposed to global.  The audio library in general seems to operate from the concept of a sinple audio manager and not supprt various instances.  I can only assume this design is to match the common restrictions of mobile and many other platforms where there is only one physical audio device.  Channel support seems very minimal within theis library as well, although the jury is still out on that one.

sdl2-loadwav - A simple wav loader with reporting of results.  

I created this to better understand the loadwav method within the audio module.  Note that there is a fair amount of redundency and creating of containers that could have been reused but help to understand how the containers are reused and what is shared.  

