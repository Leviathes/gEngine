//
// Created by lucas on 9/13/21.
//

#ifndef ADVENTUREGAME_TOOLBOX_H
#define ADVENTUREGAME_TOOLBOX_H

#include <iostream>

class Game;

namespace toolBox {




	 inline bool DBmode;
	 std::string getDir(const std::string& dir);
	 void printHelp();
	 void printHelp(const std::string& helpCommand);

	 ///Debugging error - err()
	 void err(const std::string& message);
	 void dbm(const std::string& message);
	 void handleArgs(int& argc, char* argv[], Game& g);


	 /// Templated cleanup function for ALL POINTERS!!
	 template <class T, class... Args>
	 void clean(T* t, Args&&... args){

		 clean(t);
		 clean(std::forward<Args>(args)...);

	 }

	 template<>
	 inline void clean<SDL_Window>(SDL_Window* win){
		 if(!win) {
			 return;
		 }
		 SDL_DestroyWindow(win);
	 }

	 template<>
	 inline void clean<SDL_Renderer>(SDL_Renderer* ren){
		 if(!ren) {
			 return;
		 }
		 SDL_DestroyRenderer(ren);
	 }

	 template<>
	 inline void clean<SDL_Texture>(SDL_Texture* tex){
		 if(!tex) {
			 return;
		 }
		 SDL_DestroyTexture(tex);
	 }

	 template<>
	 inline void clean<SDL_Event>(SDL_Event* ev){
		 if(!ev) {
			 return;
		 }
		 delete ev;
	 }

	 template<>
	 inline void clean <SDL_Surface>(SDL_Surface* surf){
		 if(!surf) {
			 return;
		 }
		 SDL_FreeSurface(surf);
	 }




}


#endif //ADVENTUREGAME_TOOLBOX_H
