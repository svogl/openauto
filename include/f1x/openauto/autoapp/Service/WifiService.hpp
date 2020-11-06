/*
*  This file is part of openauto project.
*  Copyright (C) 2018 f1x.studio (Michal Szwaj)
*
*  openauto is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.

*  openauto is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with openauto. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <f1x/openauto/autoapp/Configuration/IConfiguration.hpp>
#include <f1x/openauto/autoapp/Service/IService.hpp>
#include <boost/asio/io_service.hpp>
#include <f1x/aasdk/Messenger/IMessenger.hpp>

namespace f1x
{
namespace openauto
{
namespace autoapp
{
namespace service
{

class WifiService: public IService, public std::enable_shared_from_this<WifiService>
{
public:
    typedef std::shared_ptr<WifiService> Pointer;

    WifiService(configuration::IConfiguration::Pointer configuration);

    void start() override;
    void stop() override;
    void pause() override;
    void resume() override;
    void fillFeatures(aasdk::proto::messages::ServiceDiscoveryResponse& response) override;

private:
    using std::enable_shared_from_this<WifiService>::shared_from_this;
    configuration::IConfiguration::Pointer configuration_;
};

}
}
}
}
