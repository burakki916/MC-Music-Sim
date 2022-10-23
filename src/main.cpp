#include <string>
#include <iostream>
#include <filesystem>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
namespace fs = std::filesystem;

sf::Music backgroundMusic; 
std::vector<std::string> soundList;
sf::Time silenceInterval;
sf::Clock musicClock; 


void makeSongList();    
void playSong();
void manageTime(); 

int main(){
    srand(time(NULL));

    makeSongList();
    while(true){
        sf::Time elapsed = musicClock.getElapsedTime(); 
        if(elapsed>silenceInterval){
            playSong();
            manageTime();  
            musicClock.restart(); 
        }
    }
}
void makeSongList(){
    std::string path = "./Music";
    for (const auto & entry : fs::directory_iterator(path)){
        std::string itemName = entry.path().string();
        soundList.push_back(itemName);
    }
}
void playSong(){  
    std::string queuedSong; 
    int songNum = rand() % (soundList.size() - 1)+1; 
    queuedSong = soundList.at(songNum); 
    backgroundMusic.openFromFile(queuedSong);
    std::cout << "now playing : " << queuedSong << std::endl; 
    backgroundMusic.play(); 

}
void manageTime(){
    int maxTime =20;  
    int minTime = 10; 
    int silenceIntervalINT = rand() % (maxTime-minTime) + minTime; 
    silenceInterval = sf::seconds(silenceIntervalINT * 60); 
}