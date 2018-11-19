#include "Nest.h"

/*****
 * The iAnt nest needs to keep track of four things:
 *
 * [1] location
 * [2] nest id 
 * [3] site fidelity
 * [4] pheromone trails
 *
 *****/
	Nest::Nest(){}
	Nest::Nest(CVector2   location)
{
    /* required initializations */
	   nestLocation    = location;
	   departLocation  = location;
    PheromoneList.clear();
    FidelityList.clear();
    DensityOnFidelity.clear(); //qilu 09/11/2016
    FoodList.clear(); //qilu 09/07/2016
    NewLocation = location; //qilu 09/19/2016
    //num_collected_tags=0;
    visited_time_point_in_minute=0;
    nest_idx=-1;
    parent_nest_idx = -1;
    level = -1;
    travel_flag =0;
    NestRadius = 0.25;
}

/*****
 *****/

/*****
 * Return the nest's location.
 *****/
 
 
CVector2 Nest::GetLocation() {
    return nestLocation;
}

CVector2 Nest::GetDepartLocation() {
    return departLocation;
}

void Nest::SetLocation() {
    nestLocation=CVector2(0.0, 0.0);
}

void Nest::SetLocation(CVector2 newLocation) {
    nestLocation = newLocation;
}

void Nest::SetDepartLocation(CVector2 location){
	departLocation = location;
	}


void Nest:: SetNestIdx(size_t idx){
     nest_idx = idx;
 }
 
void Nest:: SetLevel(size_t l){
	level = l; 
}
 
void Nest::SetParentNestIdx_with_backtrack(size_t idx)
{
	parent_nest_idx = (idx-1)/4;
    
	}
 
void Nest::SetParentNestIdx_without_backtrack(size_t idx)
{
	parent_nest_idx = (idx-1)/4;
    
	}
 
void Nest::SetDeliveryCapacity(size_t c)
{
    capacity = c;
	
	}
     
size_t Nest::GetDeliveryCapacity()
{
    return capacity;
}
	   
size_t Nest:: GetLevel()
{
	return level;
	}
        
        
size_t Nest:: GetNestIdx(){
     return nest_idx;
 } 

size_t Nest:: GetParentNestIdx()
{
	return parent_nest_idx;
	}

size_t Nest:: GetCollectedTagNum(){
     return FoodList.size();
 } 
 
int Nest:: GetTravelFlag(){
	return travel_flag;
	}

void Nest:: SetTravelFlag(int flag){
	travel_flag = flag;
}
        
