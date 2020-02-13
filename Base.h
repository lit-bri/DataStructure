#ifndef Base_hpp
#define Base_hpp

class Base
{
public:
	struct InitInfo;
	static Base* create();
	bool init(InitInfo& info) ;
private:

};

#endif // !Base_hpp
