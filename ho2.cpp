#include <iostream>
#include <fstream>

#include <IMC/Spec/Loiter.hpp>
#include <IMC/Spec/SetEntityParameters.hpp>
#include <IMC/Spec/PlanManeuver.hpp>
#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Base/InlineMessage.hpp>


int main() {
    IMC::Loiter *loiter = new IMC::Loiter();
    loiter->timeout = 1000;
    loiter->lat = 0.7188016469344056;
    loiter->lon = -0.15194250254286037;
    loiter->z = 3;
    loiter->z_units = 1;
    loiter->duration = 300;
    loiter->speed = 1000;
    loiter->speed_units = 1;
    loiter->type = 1;
    loiter->radius = 20;
    loiter->length = 1;
    loiter->bearing = 0;
    loiter->direction = 1;
    loiter->custom = "";

    IMC::EntityParameter *ep = new IMC::EntityParameter();
    ep->name = "Active";
    ep->value ="false";
    
    IMC::SetEntityParameters *sep = new IMC::SetEntityParameters();
    sep->params.push_back(ep);
    sep->name = "LBL";

    IMC::PlanManeuver *man = new IMC::PlanManeuver();
    man->maneuver_id = "1";
    man->start_actions.push_back(sep);
    man->data.set(loiter);
    
    IMC::PlanSpecification *ps = new IMC::PlanSpecification();
    ps->setTimeStamp();
    ps->setSource(16652);
    ps->setSourceEntity(44);
    ps->setDestination(30);
    ps->setDestinationEntity(255);
    ps->plan_id = "cmd-lauv-xplore-1";
    ps->start_man_id = "1";
    ps->maneuvers.push_back(man);


    std::ofstream outputfile;
    outputfile.open("plan.json");
    ps->toJSON(outputfile);
    outputfile.close();

    return 0;
}
