/* 
 * File:   CUtilHttpRequestHandler.h
 * Author: Gavin Chan
 *
 * Created on February 2, 2016, 6:09 AM
 */

#ifndef CUTILHTTPREQUESTHANDLER_H
#define	CUTILHTTPREQUESTHANDLER_H

#include <boost/asio.hpp>

#include <iostream>

class CUtilHttpRequestHandler {
public:
    CUtilHttpRequestHandler();

	bool SendRequest(const char* address, 
					 const char* request,
					 std::string& http_response);
	
    virtual ~CUtilHttpRequestHandler();

private:
	boost::asio::io_service svc;
	
	boost::asio::ip::tcp::socket sock;

    CUtilHttpRequestHandler(const CUtilHttpRequestHandler& orig);
};

#endif	/* CUTILHTTPREQUESTHANDLER_H */

