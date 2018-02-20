/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3,
 * ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

#include "oms2_Variable.h"
#include "oms2_Logging.h"
#include "Settings.h"
#include "FMUWrapper.h"
#include "Util.h"

#include <fmilib.h>
#include <JM/jm_portability.h>

#include <iostream>
#include <string>

oms2::Variable::Variable(const oms2::ComRef& cref, fmi2_import_variable_t *var, unsigned int index)
  : is_state(false), sr(cref, fmi2_import_get_variable_name(var)), index(index)
{
  // extract the attributes
  description = fmi2_import_get_variable_description(var) ? fmi2_import_get_variable_description(var) : "";
  trim(description);
  vr = fmi2_import_get_variable_vr(var);
  causality = fmi2_import_get_causality(var);
  initialProperty = fmi2_import_get_initial(var);
  baseType = fmi2_import_get_variable_base_type(var);
}

oms2::Variable::~Variable()
{
}

bool oms2::operator==(const oms2::Variable& v1, const oms2::Variable& v2)
{
  return v1.sr == v2.sr && v1.vr == v2.vr;
}

bool oms2::operator!=(const oms2::Variable& v1, const oms2::Variable& v2)
{
  return !(v1 == v2);
}