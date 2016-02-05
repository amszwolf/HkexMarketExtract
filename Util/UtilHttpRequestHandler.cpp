/* 
 * File:   CUtilHttpRequestHandler.cpp
 * Author: Gavin Chan
 * 
 * Created on February 2, 2016, 6:09 AM
 */

#include "UtilHttpRequestHandler.h"

using namespace boost::asio::ip;

CUtilHttpRequestHandler::CUtilHttpRequestHandler() :
	svc(),
	sock(svc)
{
}

CUtilHttpRequestHandler::~CUtilHttpRequestHandler()
{
}

bool CUtilHttpRequestHandler::SendRequest(
	const char* address,
	const char* request,
	std::string& http_response)
{
	http_response.clear();
	
	try
	{
		tcp::resolver resolver(svc);
		tcp::resolver::query query(address, "http");
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

		// Try each endpoint until we successfully establish a connection.
		tcp::socket socket(svc);
		boost::asio::connect(socket, endpoint_iterator);

		boost::asio::streambuf req;

		std::ostream request_stream(&req);
		request_stream << "GET " << request << " HTTP/1.0\r\n";
		request_stream << "Host: " << address << "\r\n";
		request_stream << "Accept: */*\r\n";
		request_stream << "Connection: close\r\n\r\n";

		// Send the request.
		boost::asio::write(socket, req);

		// Read the response status line. The response streambuf will automatically
		// grow to accommodate the entire line. The growth may be limited by passing
		// a maximum size to the streambuf constructor.
		boost::asio::streambuf response;

		// Read until EOF, writing data to output as we go.
		boost::system::error_code error;
		while (boost::asio::read(socket, response,
			  boost::asio::transfer_at_least(1), error))
		{
		}

		boost::asio::streambuf::const_buffers_type b = response.data();
		std::string line(boost::asio::buffers_begin(b),
						 boost::asio::buffers_begin(b) + response.size());

		http_response = line;
	}
	catch (std::exception& ex)
	{
		return false;
	}
	
	return true;
}
