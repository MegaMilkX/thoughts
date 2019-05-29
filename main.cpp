
class Attribute;
class SceneObject;
class Behavior;
class Scene;

class SceneSession;
class SceneContext;

class attrTransform;
class attrAnimStack;
class attrModel;
class attrLightOmni;

class bhvrCharacter;
class bhvrTpsCamera;
class bhvrCollisionTrigger;

class Game {
public:
	void 
};

namespace game {

void gameStart() {
	loadLevel("test01");
	respawnPlayer();
	
	showSplashText("Hello, World!");

	SceneContext ctx;
}


void gameUpdate() {
	
}

}
