# Rythm-Mosaic Game
## About/Intro ##
I like music, and I like games. I like rythm games. Initially, when I began working, the game was going to be a generic guitar hero/tap tap/ rock band style rythm game, where notes would fall and you'd have to hit the keyboard depending on where the note fell. This had been done to death, so why not try something new. Then I realized, clicking the mouse made a sound, and doing it rythmically created a beat, So I decided to make a game that required interactively clicking the mouse to the beat of a song.

  Here are the very beginnings of my idea in a diff repo: 
[![https://github.com/vince702/Game1/tree/customKeyClass/Game]()](https://github.com/vince702/Game1/tree/customKeyClass/Game)
   

## **Objective:** 
Tiles will appear following the beat of the song on the 4x4 grid and light up green when they need to be struck with the mouse.  The goal is to improve both HitCount and MaxCombo as much as possible in each attempt through the beatmap.


COMBO: number of keys you strike accurately in a row
HitCount: number of keys struck accurately in total

###
## **Specifications** ##
Implement a timer and a hitbox. When the mouse is clicked, a hitbox will appeaer where the cursor is. If the hitbox strikes an active key, it counts as a good hit and HitCount is increased, as well as the current combo. 

If the hitbox doesn't strike a note, or if a note disappears before you hit it in time, it counts as a miss and your current combo is "broken," and your currentCombo is reset. 

## DEMO:  ##
here is a video demo of how the game is played and how it runs, (and also a showcase of how bad I am at rythm games as you can see by my whopping max combo of 9 on the second song before I gave up... Trust me it's a lot harder to play while I'm holding the phone to record.)

[![Video Demo](https://i.ytimg.com/vi/rhxR8l9KMpY/hqdefault.jpg?custom=true&w=336&h=188&stc=true&jpg444=true&jpgq=90&sp=68&sigh=1dzo380QmZRsV5mUgtGqe2qHgqo)](https://www.youtube.com/watch?v=rhxR8l9KMpY)



### Reading the Beatmap: ###
Reads from a text file, and passes two parameters of each key into two separate vectors, the time it is played and the location on the 4x4 grid, or the keyboard. Equivalent number of keys are created and put into a container, to be read by playNotes()

```

/***************************************************************
 * Generic Function to Add Keys from any vector of times and locations
 * *************************************************************/

template<typename InputIterator, typename Container>
void convertToKeys( InputIterator v1Start,InputIterator v2Start,InputIterator v1End, InputIterator v2End, Container &c ){
    while ( v1Start != v1End ){
       try {c.enqueue(key(*v1Start, *v2Start));}
        catch(std::exception &e ){
            try{
            c.push_back(key(*v1Start, *v2Start));}
            catch(std::exception &e){
                qDebug() << "invalid container";
            }
        }

        v1Start++;
        v2Start++;
    }
    return;
}


 /**********************************************************
                           LAMBDA FUNCTIONS
 **************************************************************/

    QFile f(textFileName);
    f.open(QIODevice::ReadOnly);

    std:: vector<double> timings;
    std:: vector<double> locations;

    /*  reads data from file, adds to a vector of timings and location, each entry represents the time played
        of the note, and where on the grid it will be played  */
        auto dataToVector = [&f,&timings,&locations](int &beatmapDuration){
         QTextStream s(&f);
       int songLength = 0;
       s >> beatmapDuration;
       while ( !s.atEnd() ) {
         double d;
         double f;
         s >> d;
         s >> f;
         timings.push_back(d);
         locations.push_back(f);

         qDebug() << d << "  " << f;

       }

       timings.pop_back();

      f.close();
     };

     //reads the data from the timing and location list to creat a key, and adds to queue of keys to be played
      auto getNotes = [&notes](std::vector<double> &noteTimingList,std::vector<double> &noteLocationList){

        convertToKeys(noteTimingList.begin(), noteLocationList.begin(),noteTimingList.end(),noteLocationList.end(),notes);
      };




     //calling lambda functions
      dataToVector(songDuration);
      getNotes(timings,locations);


     /**************************************************  / 
     
     
     
```





### Timer: ###
Implementation of QTimer to determine when to play a note. The timer starts, and each milisecond is checked to see if a key needs to be played.

```
    //in game_client
    QTimer * timer = new QTimer();
    Keyboard::connect(timer, SIGNAL(timeout()),k,SLOT(playNotes()));
    timer->start(1);
```
    
    
  once the note is played, it disappears when the window to strike it is up, and counts as a miss.
```
//in playNotes()
 QTimer * timer1 = new QTimer;
  paper -> addItem(note);
   key::connect(timer1, SIGNAL(timeout()),note,SLOT(updateTimingWindow()));
   int intervalLength = 100;
   timer1->start(intervalLength);   // .1 seconds per interval, has .3 seconds until note needs to be striken
```
   
   
   
   
   
   
   
