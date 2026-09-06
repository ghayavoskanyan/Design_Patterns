#include <iostream>

class IAudioProcessor
{
public:
    virtual ~IAudioProcessor() = default;
    virtual void playAudio() = 0;
    virtual void stopAudio() = 0;
    virtual void adjustVolume(int volume) = 0;
};

class IVideoProcessor
{
public:
    virtual ~IVideoProcessor() = default;
    virtual void playVideo() = 0;
    virtual void stopVideo() = 0;
    virtual void adjustBrightness(int brightness) = 0;
};

class AudioPlayer : public IAudioProcessor
{
public:
    void playAudio() override
    {
        std::cout << "Playing audio\n";
    }

    void stopAudio() override
    {
        std::cout << "Stopping audio\n";
    }

    void adjustVolume(int volume) override
    {
        std::cout << "Volume: " << volume << '\n';
    }
};

class VideoPlayer : public IVideoProcessor
{
public:
    void playVideo() override
    {
        std::cout << "Playing video\n";
    }

    void stopVideo() override
    {
        std::cout << "Stopping video\n";
    }

    void adjustBrightness(int brightness) override
    {
        std::cout << "Brightness: " << brightness << '\n';
    }
};