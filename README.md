# SecureLoginwithRegistration
Simple C++ program for secure login with registration

A simple C++ program to login and register users. The system is designed to do five things: 1) register users, 2) login users, 3) record a bio, 4) save the information in a text file, and 5) hash the password with salt prior to export. Numerous possibilities exist for development depending on the environment. For example, in its current state the system is tailored to a small number of users by creating a separate file for each. However, the code could be expanded where users' data is output to a database and compensates for an enterprise environment with various users. The purpose of this system is to demonstrate secure authentication where the passwords are salted, which prevents numerous attacks. The system of authentication delivered here, is not a silver bullet, and should not be confused as impenetrable. Never forget to include layers of defense. Stay secure, and have fun with the code!

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

The C++ Bcrypt Wrapper, which can be found at https://github.com/hilch/Bcrypt.cpp , provides the hashing algorithm in this secure authentication system. See license below:

BSD 4-Clause License

Copyright (c) 2019, Christoph Hilchenbach
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by Niels Provos.
4. The name of the author may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
