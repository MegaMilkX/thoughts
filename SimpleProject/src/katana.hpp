#ifndef KATANA_API_HPP
#define KATANA_API_HPP

class Display;
class Input;
class Audio;
class Session;

class ktAudio;
class ktInput;
class ktDisplay;
class ktSession;

// Central api for a katana application
class KatanaApi {

public:
	virtual Display&	getDisplay	(void);
	virtual Input&		getInput	(void);
	virtual Audio&		getAudio	(void);
	
	virtual void 		run			(Session*);
	virtual void		exit		(void);
};

#endif
