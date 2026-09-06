#include "ISP.cpp"

int main()
{
    AudioPlayer audioPlayer;

    audioPlayer.playAudio();
    audioPlayer.adjustVolume(80);
    audioPlayer.stopAudio();

    VideoPlayer videoPlayer;

    videoPlayer.playVideo();
    videoPlayer.adjustBrightness(70);
    videoPlayer.stopVideo();

    return 0;
}