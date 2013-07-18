#ifndef NOT_SUPPORTED_EXCEPTION_H_
#define NOT_SUPPORTED_EXCEPTION_H_

class NotSupportedException {
public:
	NotSupportedException() {};
	~NotSupportedException() {};

	const char * ShowReason() const {
		return "An unsupported operation was called!";
	}
};

#endif