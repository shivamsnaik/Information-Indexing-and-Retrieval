/* 
 * File:   video.h
 * Author: prateek
 *
 * Created on 9 April, 2016, 10:50 AM
 */

#ifndef VIDEO_H
#define	VIDEO_H

#include "newfile.h"

class video
{
protected:
   int no;
   char  c2[1000];
   char c3[1000];
   char c4[1000];
   
public:
   video()
   {
       installffmpeg();
       installpocketsphinx();
       cout<<"Enter no. of video files which you want to convert into text(less than 20):";
       cin>>no;
      for(int i=1;i<=no;i++)
      {
         
	sprintf(c2,"ffmpeg -i /home/prateek/Desktop/OOPSProject/video/vedio%d.mp4 -ar 16000 -ac 1 /home/prateek/Desktop/OOPSProject/video/audio/aud%d.mp3",i,i);
	sprintf(c3,"ffmpeg -i /home/prateek/Desktop/OOPSProject/video/audio/aud%d.mp3 -ar 16000 -ac 1 /home/prateek/Desktop/OOPSProject/video/wave/%d.wav",i,i);
        sprintf(c4,"pocketsphinx_continuous -infile /home/prateek/Desktop/OOPSProject/video/wave/%d.wav -hmm en_US/hub4wsj_sc_8k -lm en_US/hub4.5000.DMP 1> /home/prateek/Desktop/OOPSProject/video/video/video-%d",i,i);  
	system(c2);
        system(c3);
        system(c4);
      }
   }
   
   void installffmpeg()
   {
       system("sudo apt-get install ffmpeg");
   }
   
   void installpocketsphinx()
   {
       system("sudo apt-get install python-pocketsphinx");
   }
   ~video()
   {}
};
    
#endif	/* VIDEO_H */

