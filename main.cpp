#include"loader.h"
#include<iostream>
#include<string>




int main(int argc , char** argv){

   if(argc < 2 ){
      std::cout<<"expe: ./main filename [funname] to run."<<std::endl;
      //  "/home/parallels/tmpfs.srv";
      return  0;
   }

   std::string file = std::string(argv[1]);
   std::string funcname;

   if(argc == 3){
      funcname  = std::string(argv[2]);
   }

   Binary *bin = new Binary;
   load_binary(file,bin,Binary::BinaryType::BIN_TYPE_ELF);
   
   for(auto s:bin->symbols){
      if(funcname==""){
         printf("%s\t%lx\n",s.name.c_str(),s.addr);
      }
      if(s.name == funcname){
            printf("%s\t0x%lx\n",s.name.c_str(),s.addr);
            return 0;
      }
   }
   return 0;

}


