/**
 * krk_config.h - Krake configuration
 * 
 * Copyright (c) 2010 Yang Yang <paulyang.inf@gmail.com>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __KRK_CONFIG_H__
#define __KRK_CONFIG_H__

extern void krk_config_read(int sock, short type, void *arg);
extern void krk_config_write(int sock, short type, void *arg);

#define KRK_CONFIG_MAX_LEN 4096

#define KRK_CONF_CMD_CREATE 1
#define KRK_CONF_CMD_DESTROY 2
#define KRK_CONF_CMD_ADD 3
#define KRK_CONF_CMD_REMOVE 4
#define KRK_CONF_CMD_ENABLE 5
#define KRK_CONF_CMD_DISABLE 6
#define KRK_CONF_CMD_SHOW 7
#define KRK_CONF_CMD_FLUSH 8

#define KRK_CONF_TYPE_MONITOR 1
#define KRK_CONF_TYPE_NODE 2

#define KRK_CONF_RETVAL_LEN 5

#define KRK_CONF_DEFAULT_INTERVAL 5
#define KRK_CONF_DEFAULT_TIMEOUT 5
#define KRK_CONF_DEFAULT_THRESHOLD 5

struct krk_config_monitor {
	char monitor[64];
	unsigned long interval;
	unsigned long timeout;
	unsigned long threshold;
	
	char checker[64];
	unsigned long checker_param_len;

	unsigned int nr_nodes;
};

struct krk_config_node {
	char addr[64]; /* only accept ip address */
	unsigned short port;
};

struct krk_config {
	char command;
	char type;

	/* args of monitor */
	char monitor[64];
	char checker[64];
	char *checker_param; /* point to data */
	unsigned long checker_param_len;

	unsigned long interval;
	unsigned long timeout;
	unsigned long threshold;

	/* args of node */
	char node[64]; /* only accept ip address */
	unsigned short port;

	char data[0]; /* additional data */
};

struct krk_config_ret {
	int retval;
	unsigned int data_len;
};
#endif
