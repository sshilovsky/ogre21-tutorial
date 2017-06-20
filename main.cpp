#include <iostream>
#include <OgreRoot.h>

int main() {
    Ogre::Root root;
    if (!root.restoreConfig() && !root.showConfigDialog()) {
        return 2;
    }
    root.initialise(false);
    auto win = root.createRenderWindow("test", 1024, 720, false);
    auto scnMgr = root.createSceneManager(Ogre::ST_GENERIC, 2, Ogre::INSTANCING_CULLING_THREADED);

    root.startRendering();

    return 0;
}