/***************************************************************************
*   Copyright (C) 2005 by                                                 *
*   Pedro J. Fernandez Ruiz    pedroj@um.es                               *
*   Alejandro Perez Mendez     alex@um.es                                 *
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
#ifndef THREADCONTROLLERIMPL_H
#define THREADCONTROLLERIMPL_H

#include "condition.h"
#include "mutex.h"
#include "semaphore.h"
#include "ikesa.h"
#include "command.h"
#include "payload_tsi.h"
#include "payload_tsr.h"

using namespace std;

namespace openikev2 {

    /**
        This abstract class represents a ThreadController concrete implementation
        @author Alejandro Perez Mendez, Pedro J. Fernandez Ruiz <alex@um.es, pedroj@um.es>
    */
    class ThreadControllerImpl {

            /****************************** METHODS ******************************/
        public:
            /**
             * Gets a new Condition object.
             * @return A new Condition object.
             */
            virtual auto_ptr<Condition> getCondition() = 0;

            /**
             * Gets a new Mutex object.
             * @return A new Mutex object.
             */
            virtual auto_ptr<Mutex> getMutex() = 0;

            /**
             * Creates a new implementation dependent Semaphore object.
             * @return A new Semaphore object.
             */
            virtual auto_ptr<Semaphore> getSemaphore( uint32_t initial_value ) = 0;

            virtual ~ThreadControllerImpl();
    };
};
#endif
