// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BehaviorDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BEHAVIORDEFINITION
public:
    class BehaviorDefinition& operator=(class BehaviorDefinition const&) = delete;
    BehaviorDefinition(class BehaviorDefinition const&) = delete;
    BehaviorDefinition() = delete;
#endif

public:
    /*0*/ virtual ~BehaviorDefinition();
    /*1*/ virtual void load(class Json::Value, class BehaviorFactory const&);
    /*2*/ virtual std::unique_ptr<class BehaviorNode> createNode(class Actor&, class BehaviorFactory const&, class BehaviorNode*, class BehaviorData*) const;
    /*
    inline  ~BehaviorDefinition(){
         (BehaviorDefinition::*rv)();
        *((void**)&rv) = dlsym("??1BehaviorDefinition@@UEAA@XZ");
        return (this->*rv)();
    }
    */

protected:

private:

};