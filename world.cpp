class GameObject;

class ktActor;

class ktWorld {
	std::set<std::shared_ptr<ktActor>> 		actors;
	GameObject 								rootObject;
	
	ktSceneDynamics* 	dynamics 			= 0;
	ktConstraintSolver* constraint_solver 	= 0;
	ktAnimator*			animator 			= 0;
	ktRenderPartition*	render_partition 	= 0;
public:
	ktActor* 			createActor(ktActor* actor);
	GameObject* 		getRoot();
	
	GameObject*			findObject(const std::string& name);
	Attrib* 			findAttrib(const std::string& attr_type);
	std::set<Attrib*> 	findAttribs(const std::string& attr_type);
};

class ktRenderer;
class ktRenderTarget;

void ktStartup(KatanaApi* ktApi) {
	ktWorld world(
		new ktDefaultDynamics,
		new ktDefaultConstraintSolver,
		new ktDefaultAnimator,
		new ktDefaultRenderPartition
	);
	
	world.createActor(new actThirdPersonCamera, "player_camera");
	world.createActor(new actLandscape, "terrain");
	world.createActor(new actGenericCharacter("test/chara.so", "test/chara.actgraph"), "player_character");
	
	world.findAttrib("SpawnPoint");
	world.findAttribs("SpawnPoint");
	world.findObject("SomeNode");
}
