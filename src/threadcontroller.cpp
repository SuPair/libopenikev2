/***************************************************************************
*   Copyright (C) 2005 by                                                 *
*   Pedro J. Fernandez Ruiz    pedroj.fernandez@dif.um.es                 *
*   Alejandro Perez Mendez     alejandro_perez@dif.um.es                  *
*                                                                         *
*   This library is free software; you can redistribute it and/or         *
*   modify it under the terms of the GNU Lesser General Public            *
*   License as published by the Free Software Foundation; either          *
*   version 2.1 of the License, or (at your option) any later version.    *
*                                                                         *
*   This library is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
*   Lesser General Public License for more details.                       *
*                                                                         *
*   You should have received a copy of the GNU Lesser General Public      *
*   License along with this library; if not, write to the Free Software   *
*   Foundation, Inc., 51 Franklin St, Fifth Floor,                        *
*   Boston, MA  02110-1301  USA                                           *
***************************************************************************/
#include "threadcontroller.h"
#include "assert.h"

namespace openikev2 {

    ThreadControllerImpl* ThreadController::implementation =  NULL;

    void ThreadController::setImplementation( ThreadControllerImpl* impl ) {
        implementation = impl;
    }

    auto_ptr< Condition > ThreadController::getCondition( ) {
        assert (implementation != NULL);
        return implementation->getCondition();
    }

    auto_ptr< Mutex > ThreadController::getMutex( ) {
        assert (implementation != NULL);
        return implementation->getMutex();
    }

    auto_ptr< Semaphore > ThreadController::getSemaphore( uint32_t initial_value ) {
        assert (implementation != NULL);
        return implementation->getSemaphore( initial_value );
    }
}