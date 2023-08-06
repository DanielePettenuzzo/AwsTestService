FROM ubuntu:22.04 AS build-env

RUN apt update && \
    apt install -y \
      openssh-client \
      git \
      g++ \
      cmake \
      pkg-config \
      python3-pip && \
    pip install \
      conan \
      meson \
      ninja

RUN conan profile detect

COPY . /src
WORKDIR /src

FROM build-env AS builder
RUN conan build -b missing .

FROM ubuntu:22.04
COPY --from=builder /src/build/Release/apps/awesome-app/awesome-app /bin/awesome-app

CMD /bin/awesome-app