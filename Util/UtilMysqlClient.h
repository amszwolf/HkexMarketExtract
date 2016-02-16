/* 
 * File:   CUtilMysqlClient.h
 * Author: Gavin Chan
 *
 * Created on February 13, 2016, 10:24 PM
 */

#ifndef CUTILMYSQLCLIENT_H
#define	CUTILMYSQLCLIENT_H

#include <mysql++.h>

#include <string>

class CUtilMysqlClient {
public:

	/**
	 * Connect to database
	 *
	 * @param dbname Name of database
	 * @param host   Host of database
	 * @param user	 Login username
	 * @param pwd	 Login password
	 *
	 * @return true if success
	 */
    virtual bool Connect(std::string dbname,
            std::string host,
            std::string user,
            std::string pwd);

	/**
	 * Query
	 * @param queryString
	 * @return true if success
	 */
	virtual bool Query(std::string queryString);

    /**
     * Constructor 
     */
    CUtilMysqlClient();

    /**
     * Destructor 
     */
    virtual ~CUtilMysqlClient();
private:
    CUtilMysqlClient(const CUtilMysqlClient& orig);

    mysqlpp::Connection conn;

};

#endif	/* CUTILMYSQLCLIENT_H */

