// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file EPCalibrationTables.h
///
/// \author Sourav Kundu <sourav.kundu@cern.ch>

#ifndef PWGLF_DATAMODEL_EPCALIBRATIONTABLES_H_
#define PWGLF_DATAMODEL_EPCALIBRATIONTABLES_H_

#include <cmath>

#include "Common/DataModel/PIDResponse.h"
#include "Common/Core/RecoDecay.h"
#include "Common/DataModel/TrackSelectionTables.h"
#include "Framework/AnalysisDataModel.h"

namespace o2::aod
{
namespace epcalibrationtable
{
DECLARE_SOA_COLUMN(TriggerEventEP, triggereventep, bool);
DECLARE_SOA_COLUMN(Cent, cent, float);
DECLARE_SOA_COLUMN(QFT0Cx, qFT0Cx, float);
DECLARE_SOA_COLUMN(QFT0Cy, qFT0Cy, float);
DECLARE_SOA_COLUMN(QFT0Ax, qFT0Ax, float);
DECLARE_SOA_COLUMN(QFT0Ay, qFT0Ay, float);
DECLARE_SOA_COLUMN(QTPCx, qTPCx, float);
DECLARE_SOA_COLUMN(QTPCy, qTPCy, float);
DECLARE_SOA_COLUMN(QTPCLx, qTPCLx, float);
DECLARE_SOA_COLUMN(QTPCLy, qTPCLy, float);
DECLARE_SOA_COLUMN(QTPCRx, qTPCRx, float);
DECLARE_SOA_COLUMN(QTPCRy, qTPCRy, float);

// Event-plane angles
DECLARE_SOA_DYNAMIC_COLUMN(PsiFT0C, psiFT0C, [](float qx, float qy) -> float { return 0.5 * std::atan2(qy, qx); });
DECLARE_SOA_DYNAMIC_COLUMN(PsiFT0A, psiFT0A, [](float qx, float qy) -> float { return 0.5 * std::atan2(qy, qx); });
DECLARE_SOA_DYNAMIC_COLUMN(PsiTPC, psiTPC, [](float qx, float qy) -> float { return 0.5 * std::atan2(qy, qx); });
DECLARE_SOA_DYNAMIC_COLUMN(PsiTPCL, psiTPCL, [](float qx, float qy) -> float { return 0.5 * std::atan2(qy, qx); });
DECLARE_SOA_DYNAMIC_COLUMN(PsiTPCR, psiTPCR, [](float qx, float qy) -> float { return 0.5 * std::atan2(qy, qx); });

// Q-vector modules
DECLARE_SOA_DYNAMIC_COLUMN(QFT0C, qFT0C, [](float qx, float qy) -> float { return std::hypot(qx, qy); });
DECLARE_SOA_DYNAMIC_COLUMN(QFT0A, qFT0A, [](float qx, float qy) -> float { return std::hypot(qx, qy); });
DECLARE_SOA_DYNAMIC_COLUMN(QTPC, qTPC, [](float qx, float qy) -> float { return std::hypot(qx, qy); });
DECLARE_SOA_DYNAMIC_COLUMN(QTPCL, qTPCL, [](float qx, float qy) -> float { return std::hypot(qx, qy); });
DECLARE_SOA_DYNAMIC_COLUMN(QTPCR, qTPCR, [](float qx, float qy) -> float { return std::hypot(qx, qy); });

} // namespace epcalibrationtable
DECLARE_SOA_TABLE(EPCalibrationTables, "AOD", "EPCALLCOLS",
                  epcalibrationtable::TriggerEventEP,
                  epcalibrationtable::Cent,
                  epcalibrationtable::QFT0Cx,
                  epcalibrationtable::QFT0Cy,
                  epcalibrationtable::QFT0Ax,
                  epcalibrationtable::QFT0Ay,
                  epcalibrationtable::QTPCx,
                  epcalibrationtable::QTPCy,
                  epcalibrationtable::QTPCLx,
                  epcalibrationtable::QTPCLy,
                  epcalibrationtable::QTPCRx,
                  epcalibrationtable::QTPCRy,
                  epcalibrationtable::PsiFT0C<epcalibrationtable::QFT0Cx, epcalibrationtable::QFT0Cy>,
                  epcalibrationtable::PsiFT0A<epcalibrationtable::QFT0Ax, epcalibrationtable::QFT0Ay>,
                  epcalibrationtable::PsiTPC<epcalibrationtable::QTPCx, epcalibrationtable::QTPCy>,
                  epcalibrationtable::PsiTPCL<epcalibrationtable::QTPCx, epcalibrationtable::QTPCy>,
                  epcalibrationtable::PsiTPCR<epcalibrationtable::QTPCx, epcalibrationtable::QTPCy>,
                  epcalibrationtable::QFT0C<epcalibrationtable::QFT0Cx, epcalibrationtable::QFT0Cy>,
                  epcalibrationtable::QFT0A<epcalibrationtable::QFT0Ax, epcalibrationtable::QFT0Ay>,
                  epcalibrationtable::QTPC<epcalibrationtable::QTPCx, epcalibrationtable::QTPCy>,
                  epcalibrationtable::QTPCL<epcalibrationtable::QTPCLx, epcalibrationtable::QTPCLy>,
                  epcalibrationtable::QTPCR<epcalibrationtable::QTPCRx, epcalibrationtable::QTPCRy>);
using EPCalibrationTable = EPCalibrationTables::iterator;
} // namespace o2::aod
#endif // PWGLF_DATAMODEL_EPCALIBRATIONTABLES_H_
