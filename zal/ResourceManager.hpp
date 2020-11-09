#pragma once

#include "Resource.hpp"
using namespace std;

class ResourceManager
{
  public:
    
    double get(){
      return obkt->get(); 
    } 
    ResourceManager(){
      obkt = new Resource; 
    }//konstruktor 
    ~ResourceManager(){
      delete obkt; 
    }//destruktor
    ResourceManager(const ResourceManager& a){
      obkt = new Resource
      *obkt = *a.obkt; 
    }// konstruktor kopiujący
    ResourceManager(ResourceManager&& a){
      *this = move(a.obkt);
      a.obkt = nullptr; 
    }//konstruktor przenoszący
    ResourceManager& operator=(const ResourceManager& a){
      if (this != &a)
            *obkt = *a.obkt;
        return *this;
    }//kopiujący operator przypisania 
    ResourceManager& operator=(const ResourceManager&& a){
      if (this != &a){
            obkt = move(a.obkt);
            a.obkt = nullptr;}
          else
          {return *this;}
    }//przenoszący operator przypisania
  private:
    Resource *obkt;
};
