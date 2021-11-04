/*
* C/GO dll
*
Initial idea and exmaple from  https://github.com/z505/goDLL
*/

package main

import "C"
import (
	"strings"

	"github.com/armon/go-socks5"
)

/*
* This was key to make Go export a function as <Name>
* It can be seen in exports table
 */

//export StartSocks
func StartSocks(host string, port string) {

	// Some defaults
	if host == "" {
		host = "127.0.0.1"
	}
	if port == "" {
		port = "3128"
	}

	// Create a SOCKS5 server
	conf := &socks5.Config{}
	server, err := socks5.New(conf)
	if err != nil {
		panic(err)
	}

	if err := server.ListenAndServe("tcp", strings.Join([]string{host, port}, ":")); err != nil {
		panic(err)
	}
}

func main() {
	// Need a main function to make CGO compile package as C shared library
}
