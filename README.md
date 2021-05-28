# cmd_game_cpp
A CMD game inspired by the Hero Loop game created only by me.<br/>
I used sqlite database, text files and multithreaded programming. 

## What's in the game?
Login<br/>
![image](https://user-images.githubusercontent.com/51320419/119914999-d28b2780-bf61-11eb-93d8-30b6d2f882bf.png)<br/><br/>
Starting village<br/>
![image](https://user-images.githubusercontent.com/51320419/119915066-f5b5d700-bf61-11eb-9eba-8086bc1b065a.png)<br/><br/>
Shops<br/>
![image](https://user-images.githubusercontent.com/51320419/119915404-ba67d800-bf62-11eb-99b4-80c53b355b71.png)<br/><br/>
Mission Difficulty Levels<br/>
![image](https://user-images.githubusercontent.com/51320419/119915425-c9e72100-bf62-11eb-9f6e-24b9b6b1aa47.png)<br/><br/>
The mission looks like in Hero Loop<br/>
![image](https://user-images.githubusercontent.com/51320419/119915161-33b2fb00-bf62-11eb-859d-00fee840eca4.png)<br/><br/>
You can extend the map with cards.<br/>
![image](https://user-images.githubusercontent.com/51320419/119915374-a9b76200-bf62-11eb-8fbb-0c004d25fe36.png)<br/><br/>
You fight and you get cards.<br/>
![image](https://user-images.githubusercontent.com/51320419/119915312-855b8580-bf62-11eb-836d-d24738c2ba56.png)

## How to develop this project?
### New enemies
##### Fighting an opponent
![image](https://user-images.githubusercontent.com/51320419/119913561-7d014b80-bf5e-11eb-8702-472723f8d0bb.png)<br/>

Add a new type of opponent to the sqlite database.<br/>
file database.cpp / method setupGame() <br/>
![image](https://user-images.githubusercontent.com/51320419/119912591-10854d00-bf5c-11eb-8966-f04f327e3ae9.png)<br/><br/>

Well done, there is information about the new enemy in the database.<br/>

How is it expected to appear in the game?<br/>

### New cards
##### Use of acquired cards
![image](https://user-images.githubusercontent.com/51320419/119913765-03b62880-bf5f-11eb-8c96-25202e5cfa10.png)<br/>

Add a card with your opponent's name on it<br/>
file startQuestCards.cpp<br/>
![image](https://user-images.githubusercontent.com/51320419/119912927-c0f35100-bf5c-11eb-8b2e-1f8ca86204cd.png)<br/><br/>
allMapCard <- A container of enemy cards that appear on the way.<br/>
![image](https://user-images.githubusercontent.com/51320419/119913911-6b6c7380-bf5f-11eb-9a65-81ec23ac4535.png)
![image](https://user-images.githubusercontent.com/51320419/119913934-76bf9f00-bf5f-11eb-9aed-eccd31e02258.png)
![image](https://user-images.githubusercontent.com/51320419/119913981-8d65f600-bf5f-11eb-96bb-a9e447a7da62.png)<br/><br/>

allHeroCard <- A container of cards affecting a hero.<br/>
![image](https://user-images.githubusercontent.com/51320419/119913825-33fdc700-bf5f-11eb-908c-9b94afe3b254.png)<br/>
![image](https://user-images.githubusercontent.com/51320419/119913788-14ff3500-bf5f-11eb-8de6-59e54b4986f3.png)<br/>
![image](https://user-images.githubusercontent.com/51320419/119913859-4b3cb480-bf5f-11eb-9e59-b1a638ad36f1.png)<br/><br/>


allMapHeroCard <- A container of cards affecting the hero and changing an empty space on the map.<br/>
![image](https://user-images.githubusercontent.com/51320419/119915628-35c98980-bf63-11eb-9fc4-f746c5ff392d.png)
![image](https://user-images.githubusercontent.com/51320419/119914080-c1411b80-bf5f-11eb-8ff8-1a263908dc60.png)
![image](https://user-images.githubusercontent.com/51320419/119914102-cf8f3780-bf5f-11eb-8ba4-558ede86971c.png)
![image](https://user-images.githubusercontent.com/51320419/119914174-edf53300-bf5f-11eb-9aba-86a5b65960ba.png)
![image](https://user-images.githubusercontent.com/51320419/119915668-48dc5980-bf63-11eb-8998-0d04d3cf9cda.png)
<br/><br/>
Implementation of the functionality of a new card, eg HeroCard.<br/>
file startQuestCards.cpp<br/>
![image](https://user-images.githubusercontent.com/51320419/119913211-98b82200-bf5d-11eb-8ca7-02c7bd19d34f.png)<br/>



player <- Player object in full game.<br/>
champion <- Player object only on this mission.<br/>

### New maps
Interface missions.<br/>
file moveSetStarterMap.cpp / method startQuest() <br/>
![image](https://user-images.githubusercontent.com/51320419/119913422-2f84de80-bf5e-11eb-9e39-049c12d001ab.png)<br/>
Inplementation.<br/>
![image](https://user-images.githubusercontent.com/51320419/119913507-60fdaa00-bf5e-11eb-972b-81c95abc8bf3.png)<br/>
![image](https://user-images.githubusercontent.com/51320419/119914346-34e32880-bf60-11eb-9a5e-e06acad2bce4.png)<br/>
###### map.txt is a village file.<br/>
Return returns the level of the map. You specify the map level in the map name.<br/>
![image](https://user-images.githubusercontent.com/51320419/119914538-a4f1ae80-bf60-11eb-9665-c2d60c2590bb.png)
### Development restrictions
Each opponent must have a different first letter of their name. The name must be capitalized.<br/>
The mission map size must be 12x21.
#### Have fun!




