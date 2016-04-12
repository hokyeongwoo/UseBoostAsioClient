#include <iostream>
#include "boost/asio.hpp"
#include "boost/bind.hpp"
#include <vector>
#include <queue>

#include <deque>
#include <boost/thread.hpp>

// 사용자 정의 헤더 Defined
#include "../../Protocol.h"
//#include "CircularBuffer.h"

using boost::asio::ip::tcp;
using namespace std;

#define PORT_NUMBER		20000				// Port Num

#define MAX_RECEIVE_BUFFER_LEN	512			// Receive Buffer Size

#define MAX_NAME_LEN	20
#define MAX_MESSAGE_LEN	129