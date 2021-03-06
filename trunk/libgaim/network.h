/**
 * @file network.h Network API
 * @ingroup core
 *
 * gaim
 *
 * Gaim is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef _GAIM_NETWORK_H_
#define _GAIM_NETWORK_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/** @name Network API                                                     */
/**************************************************************************/
/*@{*/

/**
 * Converts a dot-decimal IP address to an array of unsigned
 * chars.  For example, converts 192.168.0.1 to a 4 byte
 * array containing 192, 168, 0 and 1.
 *
 * @param ip An IP address in dot-decimal notiation.
 * @return An array of 4 bytes containing an IP addresses
 *         equivalent to the given parameter, or NULL if
 *         the given IP address is invalid.  This value
 *         is statically allocated and should not be
 *         freed.
 */
const unsigned char *gaim_network_ip_atoi(const char *ip);

/**
 * Sets the IP address of the local system in preferences.  This
 * is the IP address that should be used for incoming connections
 * (file transfer, direct IM, etc.) and should therefore be
 * publicly accessible.
 *
 * @param ip The local IP address.
 */
void gaim_network_set_public_ip(const char *ip);

/**
 * Returns the IP address of the local system set in preferences.
 *
 * This returns the value set via gaim_network_set_public_ip().
 * You probably want to use gaim_network_get_my_ip() instead.
 *
 * @return The local IP address set in preferences.
 */
const char *gaim_network_get_public_ip(void);

/**
 * Returns the IP address of the local system.
 *
 * You probably want to use gaim_network_get_my_ip() instead.
 *
 * @note The returned string is a pointer to a static buffer. If this
 *       function is called twice, it may be important to make a copy
 *       of the returned string.
 *
 * @param fd The fd to use to help figure out the IP, or else -1.
 * @return The local IP address.
 */
const char *gaim_network_get_local_system_ip(int fd);

/**
 * Returns the IP address that should be used anywhere a
 * public IP addresses is needed (listening for an incoming
 * file transfer, etc).
 *
 * If the user has manually specified an IP address via
 * preferences, then this IP is returned.  Otherwise the
 * IP address returned by gaim_network_get_local_system_ip()
 * is returned.
 *
 * @note The returned string is a pointer to a static buffer. If this
 *       function is called twice, it may be important to make a copy
 *       of the returned string.
 *
 * @param fd The fd to use to help figure out the IP, or -1.
 * @return The local IP address to be used.
 */
const char *gaim_network_get_my_ip(int fd);

/**
 * Attempts to open a listening port ONLY on the specified port number.
 * You probably want to use gaim_network_listen_range() instead of this.
 * This function is useful, for example, if you wanted to write a telnet
 * server as a Gaim plugin, and you HAD to listen on port 23.  Why anyone
 * would want to do that is beyond me.
 *
 * This opens a listening port. The caller will want to set up a watcher
 * of type GAIM_INPUT_READ on the returned fd. It will probably call
 * accept in the callback, and then possibly remove the watcher and close
 * the listening socket, and add a new watcher on the new socket accept
 * returned.
 *
 * @param port The port number to bind to.  Must be greater than 0.
 *
 * @return The file descriptor of the listening socket, or -1 if
 *         no socket could be established.
 */
int gaim_network_listen(unsigned short port);

/**
 * Opens a listening port selected from a range of ports.  The range of
 * ports used is chosen in the following manner:
 * If a range is specified in preferences, these values are used.
 * If a non-0 values are passed to the function as parameters, these
 * values are used.
 * Otherwise a port is chosen at random by the kernel.
 *
 * This opens a listening port. The caller will want to set up a watcher
 * of type GAIM_INPUT_READ on the returned fd. It will probably call
 * accept in the callback, and then possibly remove the watcher and close
 * the listening socket, and add a new watcher on the new socket accept
 * returned.
 *
 * @param start The port number to bind to, or 0 to pick a random port.
 *              Users are allowed to override this arg in prefs.
 * @param end The highest possible port in the range of ports to listen on,
 *            or 0 to pick a random port.  Users are allowed to override this
 *            arg in prefs.
 *
 * @return The file descriptor of the listening socket, or -1 if
 *         no socket could be established.
 */
int gaim_network_listen_range(unsigned short start, unsigned short end);

/**
 * Gets a port number from a file descriptor.
 *
 * @param fd The file descriptor. This should be a tcp socket. The current
 *           implementation probably dies on anything but IPv4. Perhaps this
 *           possible bug will inspire new and valuable contributors to Gaim.
 * @return The port number, in host byte order.
 */
unsigned short gaim_network_get_port_from_fd(int fd);

/**
 * Initializes the network subsystem.
 */
void gaim_network_init(void);

/*@}*/

#ifdef __cplusplus
}
#endif

#endif /* _GAIM_NETWORK_H_ */
