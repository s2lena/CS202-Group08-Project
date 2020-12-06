#ifndef _TIMERCUSTOM_H_
#define _TIMERCUSTOM_H_
#include <thread>
#include <chrono>

class Timer {
	bool clear = false;

public:
	template <typename Function>
	void setTimeout(Function function, int delay);
	template <typename Function>
	void setInterval(Function function, int interval);
	void stop() {
		this->clear = true;
	};

};
template <typename Function>
void Timer::setTimeout(Function function, int delay) {
	this->clear = false;
	std::thread t([=]() {
		if (this->clear) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear) return;
		function();
		});
	t.detach();
}
template <typename Function>
void Timer::setInterval(Function function, int interval) {
	this->clear = false;
	std::thread t([=]() {
		while (true) {
			if (this->clear) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear) return;
			function();
		}
		});
	t.detach();
}



#endif // !_TIMERCUSTOM_H_
