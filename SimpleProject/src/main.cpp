#include "katana.hpp"

class sessMain : public ktSession {
public:
	void Update() {
		
	}
};

int ktStartup(KatanaAPI* k) {
	LOG("Simple Katana example");
	k->run(new sessMain());
}
