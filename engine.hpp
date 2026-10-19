#pragma once

namespace engine
{

    enum class EngineState
    {
        Created,
        Initialized,
        Running,
        Stopped
    };

    class Engine
    {
    public:
        Engine();
        ~Engine();

        Engine(const Engine &) = delete;
        Engine &operator=(const Engine &) = delete;

        bool initialize();
        bool start();
        void tick();
        void requestStop();
        void shutdown();

        EngineState state() const noexcept;
        bool isRunning() const noexcept;

    private:
        void processEvents();
        void update();
        void render();

        EngineState state_ = EngineState::Created;
        bool stopRequested_ = false;
    };

}